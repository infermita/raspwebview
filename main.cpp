#include <QApplication>
//#include <QWebEngineView>
//#include <QWebEnginePage>
#include <QUrl>
#include <QDebug>
#include <QWebView>
//#include <QWebEngineSettings>


class WebEnginePage : public QWebPage{
protected:
    void javaScriptConsoleMessage(
                                  const QString &message,
                                  int lineNumber,
                                  const QString &sourceID) override{
        qDebug()<<"message: " << message << " Line: " << lineNumber << "SourceID " << sourceID;
        //qDebug()<<"level: "<<level;

    }
};
/*
class MyWebEnginePage : public QWebEnginePage{
protected:
    void javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level,
                                  const QString &message,
                                  int lineNumber,
                                  const QString &sourceID) override{
        qDebug()<<"message: " << message << " Line: " << lineNumber << "SourceID " << sourceID;
        //qDebug()<<"level: "<<level;

    }
};
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    qDebug()<<" Arg" << argv[1];

    QWebView view;
    view.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    view.settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    view.settings()->setAttribute(QWebSettings::WebGLEnabled, true);
    view.settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    view.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    view.settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
    view.settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);

    WebEnginePage *myPage = new WebEnginePage;
    myPage->setParent(&view);
    view.setPage(myPage);


    view.setFixedHeight(720);
    view.setFixedWidth(1280);
    view.load(QUrl("http://192.168.2.76:8000"));

    //view.setWindowFlags(view.windowFlags() | Qt::FramelessWindowHint);

    view.show();




    /*
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);


    QWebEngineView view;
    MyWebEnginePage *myPage = new MyWebEnginePage;
    myPage->setParent(&view);
    view.setPage(myPage);
    view.setUrl(QUrl(argv[1]));
    view.setFixedHeight(720);
    view.setFixedWidth(1280);
    view.show();
    */
    return a.exec();
}
