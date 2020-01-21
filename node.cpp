#pragma once

template<class Type>
class DoublyNode
{
    private:
        Type key;
    
    public:
        DoublyNode<Type> * left{ nullptr }, * right{ nullptr };
        DoublyNode();
        DoublyNode(const Type& data);
        Type& getData();
        void setData(const Type& data);
        ~DoublyNode();
};

template<class Type>
DoublyNode<Type>::DoublyNode() : DoublyNode(nullptr)
{
}

template<class Type>
DoublyNode<Type>::DoublyNode(const Type& data)
{
    this->key = data;
}

template<class Type>
Type& DoublyNode<Type>::getData()
{
    return key;
}

template<class Type>
void DoublyNode<Type>::setData(const Type& data)
{
    this->key = data;
}

template<class Type>
DoublyNode<Type>::~DoublyNode()
{
    this->lefft, this->right = nullptr;
}