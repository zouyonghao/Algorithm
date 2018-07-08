#include "BinNode.h"
#include <algorithm>
using namespace std;

// 代码中用BinNodePosi表示节点
template <typename T> class BinTree {
  protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);

  public:
    BinTree() : _size(0), _root(NULL) {}
    BinTree(T const &e) : _size(1) { _root = new BinNode(e); }
    ~BinTree() {
        if (0 < size) {
            remove(_root);
        }
    }
    int size() const { return _size; }
    bool empty() const { return _root == NULL; }
    BinNodePosi(T) root() const { return _root; }
    BinNodePosi(T) insertAsRoot(T const &);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> *&T);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> *&T);
    int remove(BinNodePosi(T) x);
    BinTree<T> *
        secede(BinNodePosi(T)
                   x); // 将子树x从当前树中摘除，并将其转换为一颗独立子树

    template <typename VST> void travLevel(VST &visit) {
        if (_root)
            _root->travLevel(visit);
    }
    template <typename VST> void travPre(VST &visit) {
        if (_root)
            _root->travPre(visit);
    }
    template <typename VST> void travIn(VST &visit) {
        if (_root)
            _root->travIn(visit);
    }
    template <typename VST> void travPost(VST &visit) {
        if (_root)
            _root->travPost(visit);
    }
    bool operator<(BinTree<T> const &t) {
        return _root && t._root && lt(_root, t._root);
    }
    bool operator==(BinTree<T> const &t) {
        return _root && t._root && (_root == t._root);
    }
};

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x) {
    return 1 + max(stature(x->lc), stature(x->rc));
}

template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) {
    while (x) {
        updateHeight(x); // 可优化，如果高度未变则停止
        x = x->parent;
    }
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const &e) {
    _size = 1;
    _root = new BinNode(e);
    return _root;
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const & e) {
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const & e) {
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}