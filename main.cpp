#include "mainwindow.h"

#include <QApplication>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QUrl>
#include <QDebug>

class MyWebEnginePage : public QWebEnginePage{
protected:
    void javaScriptConsoleMessage(QWebEnginePage::JavaScriptConsoleMessageLevel level,
                                  const QString &message,
                                  int lineNumber,
                                  const QString &sourceID) override{
        qDebug()<<"message: "<<message;
        qDebug()<<"level: "<<level;

    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    //MainWindow w;
    //w.show();
    QWebView view;
    view.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    view.settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    view.settings()->setAttribute(QWebSettings::WebGLEnabled, true);
    view.settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    view.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    view.show();
    view.load(QUrl("http://localhost:8000"));
    */
    QWebEngineView view;
    //MyWebEnginePage *myPage = new MyWebEnginePage;
    //myPage->setParent(&view);
    //view.setPage(myPage);
    view.setUrl(QUrl("http://localhost:8000"));
    view.setFixedHeight(720);
    view.setFixedWidth(1280);
    view.show();
    return a.exec();
}
