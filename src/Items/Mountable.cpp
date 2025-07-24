//
// @brief: 挂载基类
// @author: Ma Xin
//


#include "Mountable.h"

void Mountable::unmount() {
    mounted = false;
}

bool Mountable::isMounted() const {
    return mounted;
}

void Mountable::mountToParent() {
    mounted = true;
}
