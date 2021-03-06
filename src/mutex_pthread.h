/* 
 * Copyright (C) 2012 Simon Richter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef librevisa_mutex_pthread_h_
#define librevisa_mutex_pthread_h_ 1

#include <pthread.h>

namespace librevisa {

class condvar;

class mutex
{
public:
        mutex() throw() { pthread_mutex_init(&impl, 0); }
        ~mutex() throw() { pthread_mutex_destroy(&impl); }

        void lock() throw() { pthread_mutex_lock(&impl); }
        void unlock() throw() { pthread_mutex_unlock(&impl); }

private:
        pthread_mutex_t impl;
        friend class condvar;
};

}

#endif
