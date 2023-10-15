# 문제이해
BST의 일종으로 
bst의 경우 입력 순서에 따라 경사지게 트리가 구성될수 있다.
이런 경우 검색,삽입,삭제 등의 연산이 최악의 경우 O(N)이 되게되어 성능 저하가 발생한다.
원래의 취지에 맞게  O(N log N)이 되게하기 위해서는 균형을 잡아주어여한다.

avl tree는 bst의 균형을 잡게해주는 자료구조이자 알고리즘의 하나이다.

검색은 bst와 동일하며
삽입 삭제의 경우 동작 전에는 균형이 맞는 상태이므로
동작 이후 균형이 맞는지를 확인한다.
balance factor를 확인한다.
- 입력한 곳을 중심으로 확인하면 되지 않을까?
    모든 곳(노드)에서 확인해야하는가?


- insert의 경우 입력한 곳에서부터 바로 위에 조상노드들부터 거슬러 올라가면서 확인하면 된다.
    - 부모노드의 유무에 따라 성능이 달라질 수 있다.
    - 없다면 노드마다 차지하는 메모리는 감소하지만
        BF(Balance Factor)를 찾을 때마다 조상노드를 찾는 작업에서 매번 찾느라 꽤 걸릴 것이다.
        BF를 맞춘 다음에도 다시 그 위로 거슬로 올라가며 BF를 확인해야할 필요가 있을까?

- delete
    - BST룰에 따라 삭제한다.
    - 이후에 BF를 확인한다.


# 문제재정의
균형이진탐색트리인 AVL트리를 구현한다.
- BST를 만족해야하며 insert, delete할때 BF를 확인한다. 
{-1 <= BF <= 1} 에 위치한다.
즉, BF < -1 , BF > 1인 경우 BF 1이하 -1 이상이 되도록 재조정해주어야한다.
search 연산의 경우 동일하다.


# 문제해결방법
- BST구현
    - Node
        - member variable
            - node_ptr      _parent
            - node_ptr      _left_child
            - node_ptr      _right_child
            - value_type    value
        -method
            - constructor
            - destructor 보류
    - Tree
        - member variable
            - node_ptr _root
            - element_count 보류
        -method
            - constructor
            - copy assign operator
            - print
            - find
                - find using parameter value
            - insert
                - only take one value_type parameter
            - delete
            - clear
- AVL
    - BST에 덧대어서 구현한다.
    - _parent노드 확인 철저
    - insert, delete마다 BF확인
    - BF
        - get_diff(left_subtree_height - right_subtree_height)
        - get_height()
            - 자식노드 마다 깊이를 1씩 더해서 구한다.

    - Tree
        - member variable
            - BST와 동일
        - method
            - BST +@
            - BF
            - insert
                <!-- single element (1)	
                pair<iterator,bool> insert (const value_type& val);
                with hint (2)	
                iterator insert (iterator position, const value_type& val);
                range (3)	
                template <class InputIterator>
                void insert (InputIterator first, InputIterator last); -->
            - delete
                - find successor node
                    - left side
                    - right side
                    - return void or size_type
                     
            - rebalance
                - check BF from parent node of changed node
                 - balance factor
                    - diff height
                        - get left, right child node height
                    <!-- - height 차이마다 처리가 달리진다. -->
                    - 현재 변동이 생긴 노드로부터 "부모노드"들의 BF를 확인하며서 거슬러 올라간다.
            - 언제 확인해야하는가?
                - insert, delete한 이후에 확인이 필요하다.


# 검증 



# 실행



# 회고


