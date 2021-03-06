/** \file LocalListener.h
\brief The have local server, to have unique instance, and send arguments to the current running instance
\author alpha_one_x86
\version 0.3
\date 2010
\licence GPL3, see the file COPYING */

#ifndef LOCALLISTENER_H
#define LOCALLISTENER_H

#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>
#include <QStringList>
#include <QString>
#include <QCoreApplication>
#include <QFSFileEngine>
#include <QMessageBox>
#include <QTimer>
#include <QList>

#include "Environment.h"
#include "ExtraSocket.h"
#include "GlobalClass.h"

/** \brief To have unique instance, and pass arguments to the existing instance if needed */
class LocalListener : public QObject, public GlobalClass
{
    Q_OBJECT
public:
	explicit LocalListener(QObject *parent = 0);
	~LocalListener();
public slots:
	/// try connect to existing server
	bool tryConnect();
	/// the listen server
	void listenServer();
private:
	QLocalServer localServer;
	QTimer TimeOutQLocalSocket;
	typedef struct {
		QLocalSocket * socket;
		QByteArray data;
		int size;
		bool haveData;
	} composedData;
	QList<composedData> clientList;
private slots:
	//the time is done
	void timeoutDectected();
	/// \brief Data is incomming
	void dataIncomming();
	/// \brief Deconnexion client
	void deconnectClient();
	/// LocalListener New connexion
	void newConnexion();
	#ifdef ULTRACOPIER_DEBUG
	/** \brief If error occured at socket
	\param theErrorDefine The error define */
	void error(QLocalSocket::LocalSocketError theErrorDefine);
	#endif
	/// \can now parse the cli
	void allPluginIsloaded();
signals:
	void cli(const QStringList &ultracopierArguments,const bool &external,const bool &onlyCheck);
};

#endif // LOCALLISTENER_H
