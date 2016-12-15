#!/bin/bash

if "$HOME/Qt5.8.0/5.8/ios/bin/qmake" -spec macx-ios-clang CONFIG+=iphonesimulator CONFIG+=simulator MacroinvertebrateV3.pro CONFIG+=qml_debug; then
	say 'QMake complete.'
else
	say 'QMake failed.'
	exit 1
fi

if make -j4; then
	say 'Make complete.'
else
	say 'Make failed.'
	exit 1
fi

open Macroinvertebrates.xcodeproj
say 'Opening XCode.'
exit 0