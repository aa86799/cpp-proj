//
// Created by stone on 2022/9/9.
//

#include "Foo.h"

ostream &operator<<(ostream &os, const Foo &foo) {
    return os << foo.price << " " << foo.weight << " ";
}
