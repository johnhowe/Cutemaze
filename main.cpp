/***********************************************************************
 *
 * Copyright (C) 2008 Lars Petter Mostad
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

#include "window.h"
#include "ATKCode.h"

int main(int argc, char** argv)
{
	char *argvHTK[] = {argv[0] , "-C", "settings.cfg", NULL};   // CL arguments for HTK
	if(inithtk(3, argvHTK, "CuteMaze 1.0.1", TRUE) < -1){		// Expanded FAIL to -1
		printf("Error: cannot initialise HTK\n"); exit(-1); 
	}

	QApplication app(argc, argv);
	app.setApplicationName("CuteMaze");
	app.setOrganizationDomain("gottcode.org");
	app.setOrganizationName("GottCode");

	QTranslator qt_translator;
	qt_translator.load("qt_" + QLocale::system().name());
	app.installTranslator(&qt_translator);

	QTranslator cutemaze_translator;
	cutemaze_translator.load("cutemaze_" + QLocale::system().name());
	app.installTranslator(&cutemaze_translator);

	Window window;
	window.show();
	return app.exec();
}
