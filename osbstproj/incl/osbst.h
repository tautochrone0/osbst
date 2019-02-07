/**
 *
 * @file: osbst.h
 * @author: Daniel Angelov <tautochrone4@gmail.com>
 *
 * @brief: Implementation of Order Statistics Tree (variant of Binary Search Tree)
 *        Ref: https://en.wikipedia.org/wiki/Order_statistic_tree
 *
 *        Supported operations:
 *
 *          (1) Insertion. Operation complexity O(h)
 *          (2) Median value retrieval. Operation complexity O(h)
 *
 *          where h = height of the BST.
 *
 *  @note For achieving worst-case complexity O(logn) for operations (1) and (2), a self-banacing tree can be used insted of ordinary BST.
 */
#ifndef _OSBST_H__
#define _OSBST_H__

class OSBST
{
private:
    struct Node {
        int   size;
        int   data;
        Node* left;
        Node* right;
    };

    Node* root;

    void  insertNode(Node* node, int x);
    Node* createNode(int x);
    int   selectNode(Node* node, int i);
    int   sizeofNode(Node* node);

    void freeAllNodes(Node* node);

public:

    /** @breif Class constructor
     */
    OSBST();

    /** @breif Class destructor
    */
    ~OSBST();

    /**
     * @breif Inserts an integer x in the tree.
     *
     * @param[in] integer.
     * @retval none
     */
    void Insert(int x);

    /**
     * @breif Finds the median value of the elements of the tree.
     *
     * @retval the median value.
     */
    float MedianValue();
};

#endif  /* _OSBST_H__ */