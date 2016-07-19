#ifndef ASIOCLIENT_H
#define ASIOCLIENT_H

#include <QObject>
#include <thread>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <QObject>
#include <QString>
#include <memory>

class AsioClient : public QObject
{
    Q_OBJECT
public:
    AsioClient();
    virtual ~AsioClient();

    // http://127.0.0.1/todo/
    void Get(const QString& url, const QString& path);

    void handle_resolve(const boost::system::error_code& err,
                        boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
    void handle_connect(const boost::system::error_code& err,
                        boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
    void handle_write(const boost::system::error_code& err);
    void handle_read_line(const boost::system::error_code& err);
    void handle_read_header(const boost::system::error_code& err);
    void handle_read_content(const boost::system::error_code& err);

private:
    boost::asio::io_service ioservice;
    std::shared_ptr<boost::asio::io_service::work> work;
    std::thread worker;

    std::ostringstream oss;

    std::string server, path;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf requestbuf;
    boost::asio::streambuf responsebuf;

signals:
    void read_finish(const QString& msg);
    void read_failed(const QString& msg);
};

#endif // ASIOCLIENT_H
