#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QObject>
#include <QDebug>

#include <algorithm>  // std::sort

#include "datamanager.h"

#include "views/homeview.h"
#include "views/syncview.h"
#include "views/streamview.h"
#include "views/aboutview.h"
#include "views/singlestreamview.h"

class Application : public QApplication
{
    QString masterStylesheet =  "background-repeat: no-repeat;"
                                "background-image: url(:/media/background-plain.png);"
                                "background-position: top center;"
                                "background-color: rgb(255, 255, 255);";

    AboutView aboutView;
    HomeView homeView;
    SyncView syncView;
    StreamView streamView;
    SingleStreamView singleStreamView;

    DataManager manager;
public:
    Application(int argc, char *argv[]);

public slots:
    void transitionHomeToSync();
    void transitionHomeToStream();
    void transitionStreamToHome();

    void transitionAboutToHome();
    void transitionHomeToAbout();

    void transitionStreamsToSingleStream(const QString &streamName);
    void transitionSingleStreamToStreams();
};

#endif // APPLICATION_H
