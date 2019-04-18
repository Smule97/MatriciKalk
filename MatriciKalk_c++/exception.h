#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>
class Exception{
private:
    QString error;
public:
    Exception(const QString& s="errore") : error(s) {}
    QString getError() const;
};
#endif // EXCEPTION_H
