/** \file CliParser.h
\brief To group into one class, the CLI parsing
\author alpha_one_x86
\version 0.3
\date 2010
\licence GPL3, see the file COPYING */

#ifndef CLIPARSER_H
#define CLIPARSER_H

#include <QObject>
#include <QMessageBox>
#include <QCoreApplication>
#include <QFile>

#include "Environment.h"

/** \brief class to parse all command line options */
class CliParser : public QObject
{
	Q_OBJECT
public:
	explicit CliParser(QObject *parent = 0);
public slots:
	/** \brief method to parse the ultracopier arguments
	  \param ultracopierArguments the argument list
	  \param external true if the arguments come from other instance of ultracopier
	*/
	void cli(const QStringList &ultracopierArguments,const bool &external,const bool &onlyCheck);
signals:
	/** new copy without destination have been pased by the CLI */
	void newCopy(QStringList sources);
	/** new copy with destination have been pased by the CLI */
	void newCopy(QStringList sources,QString destination);
	/** new move without destination have been pased by the CLI */
	void newMove(QStringList sources);
	/** new move with destination have been pased by the CLI */
	void newMove(QStringList sources,QString destination);
	/** new transfer list pased by the CLI */
	void newTransferList(QString engine,QString mode,QString file);
private:
	/** \brief show the help
	 *\param incorrectArguments if the help is call because the arguments are wrong */
	void showHelp(const bool &incorrectArguments=true);
};

#endif // CLIPARSER_H
