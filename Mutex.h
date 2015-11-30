/*
    https://github.com/gekomad/ThreadPool
    Copyright (C) Giuseppe Cannella

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef _WIN32

#include <windows.h>

class Mutex {
private:
    volatile LONG _lock;

public:

    void lock() {
        while (true) {
            if (!_InterlockedExchange((LPLONG)(&_lock), 1))
                return;
            while (_lock);
        }
    }

    void unlock() { _lock = 0; }

};

#else

#include <mutex>

class Mutex : public mutex {

};

#endif