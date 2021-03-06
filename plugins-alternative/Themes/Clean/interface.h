/** \file interface.h
\brief Define the interface
\author alpha_one_x86
\version 0.3
\date 2010 */

#ifndef INTERFACE_TEST_H
#define INTERFACE_TEST_H

#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QCloseEvent>

#include "../../../interface/PluginInterface_Themes.h"

namespace Ui {
	class interface;
}

/// \brief Define the interface
class InterfacePlugin : public PluginInterface_Themes
{
	Q_OBJECT
public slots:
	//send information about the copy
	/// \brief to set the action in progress
	void actionInProgess(EngineActionInProgress);
	/// \brief new transfer have started
	void newTransferStart(const ItemOfCopyList &item);
	/** \brief one transfer have been stopped
	 * is stopped, example: because error have occurred, and try later, don't remove the item! */
	void newTransferStop(const quint64 &id);
	/// \brief the new folder is listing
	void newFolderListing(const QString &path);
	/** \brief show the detected speed
	 * in byte per seconds */
	void detectedSpeed(const quint64 &speed);
	/** \brief show the remaining time
	 * time in seconds */
	void remainingTime(const int &remainingSeconds);
	/// \brief set the current collision action
	void newCollisionAction(const QString &action);
	/// \brief set the current error action
	void newErrorAction(const QString &action);
	/// \brief set one error is detected
	void errorDetected();
	//speed limitation
	/** \brief the max speed used
	 * in byte per seconds, -1 if not able, 0 if disabled */
	bool setSpeedLimitation(const qint64 &speedLimitation);
	//set the translate
	void newLanguageLoaded();
	void synchronizeItems(const QList<returnActionOnCopyList>& returnActions);
public:
	/// \brief the transfer item with progression
	struct ItemOfCopyListWithMoreInformations
	{
		quint64 currentProgression;
		ItemOfCopyList generalData;
		ActionTypeCopyList actionType;
		bool custom_with_progression;
	};
	/// \brief returned first transfer item
	struct currentTransfertItem
	{
		quint64 id;
		bool haveItem;
		QString from;
		QString to;
		QString current_file;
		int progressBar_file;
	};
	/// \brief get the widget for the copy engine
	QWidget * getOptionsEngineWidget();
	/// \brief to set if the copy engine is found
	void getOptionsEngineEnabled(bool isEnabled);
	/// \brief get action on the transfer list (add/move/remove)
	void getActionOnList(const QList<returnActionOnCopyList> &returnActions);
	//get information about the copy
	/// \brief show the general progression
	void setGeneralProgression(const quint64 &current,const quint64 &total);
	/// \brief show the file progression
	void setFileProgression(const QList<ProgressionItem> &progressionList);
	/// \brief set collision action
	void setCollisionAction(const QList<QPair<QString,QString> > &);
	/// \brief set error action
	void setErrorAction(const QList<QPair<QString,QString> > &);
	/// \brief set the copyType -> file or folder
	void setCopyType(CopyType);
	/// \brief set the copyMove -> copy or move, to force in copy or move, else support both
	void forceCopyMode(CopyMode);
	/// \brief set if transfer list is exportable/importable
	void setTransferListOperation(TransferListOperation transferListOperation);
	/** \brief set if the order is external (like file manager copy)
	 * to notify the interface, which can hide add folder/filer button */
	void haveExternalOrder();
	/// \brief set if is in pause
	void isInPause(bool);
signals:
	#ifdef ULTRACOPIER_PLUGIN_DEBUG
	/// \brief To debug source
	void debugInformation(DebugLevel level,QString fonction,QString text,QString file,int ligne);
	#endif
	//set the transfer list
	void removeItems(QList<int> ids);
	void moveItemsOnTop(QList<int> ids);
	void moveItemsUp(QList<int> ids);
	void moveItemsDown(QList<int> ids);
	void moveItemsOnBottom(QList<int> ids);
	void exportTransferList();
	void importTransferList();
	//user ask ask to add folder (add it with interface ask source/destination)
	void userAddFolder(CopyMode);
	void userAddFile(CopyMode);
	void urlDropped(QList<QUrl> urls);
	//action on the copy
	void pause();
	void resume();
	void skip(quint64 id);
	void cancel();
	//edit the action
	void sendCollisionAction(QString action);
	void sendErrorAction(QString action);
	void newSpeedLimitation(qint64);
public:
	//constructor and destructor
	InterfacePlugin(FacilityInterface * facilityEngine);
	~InterfacePlugin();
private:
	Ui::interface *ui;
	quint64 currentFile;
	quint64 totalFile;
	quint64 currentSize;
	quint64 totalSize;
	void updateTitle();
	QMenu *menu;
	EngineActionInProgress action;
	void closeEvent(QCloseEvent *event);
	void updateModeAndType();
	bool modeIsForced;
	CopyType type;
	CopyMode mode;
	bool haveStarted;
	QList<ItemOfCopyListWithMoreInformations> InternalRunningOperation;
	int loop_size,index_for_loop;
	int sub_loop_size,sub_index_for_loop;
	currentTransfertItem getCurrentTransfertItem();
	FacilityInterface * facilityEngine;
private slots:
	void forcedModeAddFile();
	void forcedModeAddFolder();
	void forcedModeAddFileToCopy();
	void forcedModeAddFolderToCopy();
	void forcedModeAddFileToMove();
	void forcedModeAddFolderToMove();
};

#endif // INTERFACE_TEST_H
