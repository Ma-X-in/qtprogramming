//
// @brief: 挂载基类
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_MOUNTABLE_H
#define QTPROGRAMMING_MOUNTABLE_H

class Mountable {
public:
    virtual void mountToParent();
    virtual void unmount();
    [[nodiscard]] bool isMounted() const;
    virtual void update()=0;

private:
    bool mounted{};
};

#endif //QTPROGRAMMING_MOUNTABLE_H
