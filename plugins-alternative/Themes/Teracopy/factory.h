/** \file factory.h
\brief Define the factory
\author alpha_one_x86
\version 0.3
\date 2010 */

#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QCloseEvent>

#include "../../../interface/PluginInterface_Themes.h"
#include "interface.h"
#include "Environment.h"

/// \brief Define the factory, to create instance of the interface
class Factory : public PluginInterface_ThemesFactory
{
	Q_OBJECT
	Q_INTERFACES(PluginInterface_ThemesFactory)
public:
	/// \brief to return the instance of the copy engine
	PluginInterface_Themes * getInstance();
	/// \brief set the resources, to store options, to have facilityInterface
	void setResources(OptionInterface * optionsEngine,const QString &writePath,const QString &pluginPath,FacilityInterface * facilityEngine,bool portableVersion);
	/// \brief to get the default options widget
	QWidget * options();
	/// \brief to get a resource icon
	QIcon getIcon(const QString &fileName);
public slots:
	void resetOptions();
	void newLanguageLoaded();
signals:
	void reloadLanguage();
	#ifdef ULTRACOPIER_PLUGIN_DEBUG
	/// \brief To debug source
	void debugInformation(DebugLevel level,QString fonction,QString text,QString file,int ligne);
	#endif
private:
	FacilityInterface * facilityEngine;
};

#endif // FACTORY_H
