#ifndef RPNTREE_EITHER_H
#define RPNTREE_EITHER_H

template<typename T>
class ErrorableValue {

public:
    explicit ErrorableValue(T value) {
        this->value = value;
        this->errorCode = false;
    }

    explicit ErrorableValue(int errorCode, bool flag) {
        this->errorCode = errorCode;
        this->error = flag;
    }

    static ErrorableValue *fromError(int code) {
        return new ErrorableValue(code, true);
    }

    static ErrorableValue *fromValue(T value) {
        return new ErrorableValue(value);
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
