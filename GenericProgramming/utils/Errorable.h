#ifndef RPNTREE_EITHER_H
#define RPNTREE_EITHER_H

#include "ErrorCodes.h"

template<typename T>
class Errorable {

public:
    explicit Errorable(T value) {
        this->value = value;
        this->errorCode = false;
        this->error = false;
    }

    explicit Errorable(int errorCode, bool markAsError) {
        this->errorCode = errorCode;
        this->error = markAsError;
    }

    static Errorable *fromError(int code) {
        return new Errorable(code, true);
    }

    static Errorable *okCode() {
        return new Errorable(OK, false);
    }

    static Errorable *ok(T value) {
        return new Errorable(value);
    }

    T getValue() {
        return value;
    }

    int getErrorCode() {
        return errorCode;
    }

    bool isError() const {
        return error;
    }

private:
    T value;
    int errorCode;
    bool error;
};


#endif //RPNTREE_EITHER_H
