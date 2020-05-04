#include <iostream>

using namespace std;

template<class T>
class TreeNode{
public:
    TreeNode(T data):_data(data){

    }

    void setData(T data){
        _data = data;
    }

    T getData(){
        return _data;
    }

    void setLeftChild(TreeNode<T>* node){
        leftChild=node;
    }

    void setRightChild(TreeNode<T>* node){
        rightChild=node;
    }

private:
    T _data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
};

template<class T>
class BinaryTree{
public:
    BinaryTree(TreeNode<T>* root):_root(root){

    }
    void insertNode();
    void search();
    void deleteNode();
    void setRoot(TreeNode<T>* root){
        _root=root;
    }
    void print();

private:
    TreeNode<T>* _root;
};

TreeNode<int>* createBSTNodewithMinimalHeight(int sortedDataInIncreasingOrder[], int minIndex,int maxIndex) {
    if(minIndex > maxIndex){
        return nullptr;
    }
    int middleIndex= (minIndex + maxIndex)/2;
    TreeNode<int>* node = new TreeNode<int>(sortedDataInIncreasingOrder[middleIndex]);
    node->setLeftChild(createBSTNodewithMinimalHeight(sortedDataInIncreasingOrder, minIndex, middleIndex -1));
    node->setRightChild(createBSTNodewithMinimalHeight(sortedDataInIncreasingOrder, middleIndex + 1, maxIndex));
    return node;
}



BinaryTree<int>* createBSTwithMinimalHeight(int sortedDataInIncreasingOrder[], int length){
    TreeNode<int>* rootNode = createBSTNodewithMinimalHeight(sortedDataInIncreasingOrder, 0,length-1);
    BinaryTree<int>* tree = new BinaryTree<int>(rootNode);
    return tree;
}


void unitTestMinimalTree(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    int length_arr = 7;
    BinaryTree<int>* minimalTree = createBSTwithMinimalHeight(arr, length_arr);
    cout << "Binary Tree with minimal length created" << endl;
}


int main()
{
    cout << "Hello World!" << endl;
    //!Following code is a sample on using the tree API

    /*
    TreeNode<int> *node_1 = new TreeNode<int>(1);
    TreeNode<int> *node_2 = new TreeNode<int>(2);
    TreeNode<int> *node_3 = new TreeNode<int>(3);

    node_1->setLeftChild(node_2);
    node_1->setRightChild(node_3);

    BinaryTree<int>* tree = new BinaryTree<int>(node_1); */

    //!
    //! \brief unitTestMinimalTree: Running this to test Minmal tree implementation.
    //!
    unitTestMinimalTree();

    return 0;
}
