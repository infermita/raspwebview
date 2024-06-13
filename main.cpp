#include <QApplication>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QUrl>
#include <QDebug>
#include <QWebView>
#include <QWebEngineSettings>



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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();
    /*
    QWebView view;
    view.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    view.settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    view.settings()->setAttribute(QWebSettings::WebGLEnabled, true);
    view.settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    view.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    MyWebEnginePage *myPage = new MyWebEnginePage;
    myPage->setParent(&view);
    view.setPage(myPage);


    view.setFixedHeight(720);
    view.setFixedWidth(1280);
    view.load(QUrl("http://localhost:8000"));

    //view.setWindowFlags(view.windowFlags() | Qt::FramelessWindowHint);

    view.show();


    */
    qDebug()<<" Arg" << argv[1];

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

    return a.exec();
}
