#define BinNodePosi(T) BinNode<T> *
#define stature(p) ((p) ? (p)->height : -1)

typedef enum { RB_RED, RB_BLACK } RBColor; // for red-black tree

template <typename T> struct BinNode {
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;
    int npl;
    RBColor color;

    BinNode()
        : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) parent = NULL, BinNodePosi(T) lc = NULL,
            BinNodePosi(T) rc = NULL, int h = 0, int npl = 1,
            RBColor c = RB_RED)
        : data(e), parent(parent), lc(lc), rc(rc), height(h), npl(npl),
          color(c) {}

    int size();
    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();
    template <VST> void travLevel(VST &); // 子树层次遍历
    template <VST> void travIn(VST &);    // 子树中序遍历
    template <VST> void travPre(VST &);   // 子树前序遍历
    template <VST> void travPost(VST &);  // 子树后序遍历
};

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const &e) {
    return lc = new BinNode(e, this); // 此处传入this作为父节点
}
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const &e) {
    return rc = new BinNode(e, this);
}
template <typename T> int BinNode<T>::size() {
    int s = 1;
    if (lc)
        s += lc->size();
    if (rc)
        s += rc->size();
}

// x 为实例，p 为指针
#define IsRoot(x) (!((x).parent)) // ((x).parent == NULL)
#define IsLChild(x) (!IsRoot(x) && ((x).parent->lc) == (&x))
#define IsRChild(x) (!IsRoot(x) && ((x).parent->rc) == (&x))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc) // ((x).lc != NULL)
#define HasRChild(x) ((x).rc) // ((x).rc != NULL)
#define HasChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))

// 兄弟节点
#define sibling(p) (IsLChild(*p) ? ((p)->parent->rc) : ((p)->parent->lc))
// 叔叔
#define uncle(p)                                                               \
    (IsLChild(*((p)->parent)) ? (x)->parent->parent->rc                        \
                              : (x)->parent->parent->lc)

// 来自父节点的引用
// 此时x是实例，这个方法得到指针?
// 在哪用到的？
// 删除时可以用到，用于把父节点的指针置为NULL
#define FromParentTo(x)                                                        \
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))
