#ifndef CMAKELISTS_H
#define CMAKELISTS_H

#include <QString>
#include <QMap>
#include <QList>

class CMakeLists
{
public:
    CMakeLists();

    void SetProjectName(const QString&);
    void AddCMakeFlags(const QString&, const QString&);
    void AddDefine(const QString&);
    void AddIncludeDirectory(const QString&);
    void AddSource(const QString&, const QString&);

    QString GenerateCMakeLists();

private:
    QString projectName;
    QMap<QString, QString> cmakeFlags;
    QList<QString> includeDirectories;
    QMap<QString, QString> sources;
    QList<QString> defines;
};

#endif // CMAKELISTS_H
