#pragma once
#include <stdexcept> //std::logic_error

template <typename T>
class SmartPtr {
public:
    SmartPtr() = default;

    explicit SmartPtr(T* raw_ptr) noexcept
        : ptr_(raw_ptr) {
    }

    SmartPtr(const SmartPtr&) = delete;

    ~SmartPtr() {
        delete ptr_;
    }

    T* GetRawPtr() const noexcept {
        return ptr_;
    }

    T* Release() noexcept {
        T* p = ptr_;
        ptr_ = nullptr;
        return p;
    }

    explicit operator bool() const {
        return ptr_ != nullptr;
    }

    T* operator->() const {
        using namespace std::literals;
        if (!ptr_) {
            throw std::logic_error("Smart ptr is null"s);
        }
        return ptr_;
    }

    T& operator*() const {
        using namespace std::literals;
        if (!ptr_) {
            throw std::logic_error("Smart ptr is null"s);
        }
        return *ptr_;
    }

private:
    T* ptr_ = nullptr;
};
