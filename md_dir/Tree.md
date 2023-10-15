Tree.md

값의 추가 방식
자식 노드의 개수
bst로 간다.

# Binary Search Tree
## 문제이해
Binary Search Tree를 구현한다.
BST란 부모노드보다 작으면 왼쪽, 크면 오른쪽에 위치하는 이진트리이다
동일한 값을 허용되지 않는다.

### 구현에 필요한 것
- 데이터
    - tree
        - Root Node
        - size
    - Node
        - Data
        - left_child_node_ptr
        - right_child_node_ptr

- 동작
    - search
        - 찾고자하는 값을 찾게한다.
        - bst룰을 이용한다.
            - 나보다 작으면 왼쪽 크면 오른쪽으로 이동한다.
            - 중복된 값은 있을 수 없다.
            - 못찾으면 NULL을 return한다.
            - pre,post,in order등의 방식이 있지만 어떻게 구현할지는 자유
    - insert
        - 입력하고자하는 값, 혹은 node(값을 미리 넣고서 진행)를 삽입한다.
        - search부터 진행한다
            - 달라지는 점은 넣고자 하는 값이므로 이미 트리에 없을 확률이 높기에(있다면 삽입 불가)
              넣을 수 있는 위치의 부모 노드에서 자식노드에 추가하는 식으로 진행해야한다.
        - search()함수를 쓸수도 있고 아닐 수도 있다.
            - 쓴다면 
                - 이전 위치를 받는 별도의 search_parent라는 것을 만들거나
                - parent_node_ptr 이라는 변수를 만들어서 각 노드마다 부모노드의 위치를 기록한다.
            - 안쓴다면
                - while문으로 반복해서 넣고자하는 위치 이전에 부모노드에서 자식노드로 입력하고자 했던 node혹은 값을 추가한다.(값은 경우 node로 만들어야함)
        - 입력되는 것의 경우 STL::map의 경우 값으로 들어온다
            - 그러므로 값으로 입력받고 그 값을 node로 만들어서 처리해주는 것이 나을 것으로 판단된다.
            - 값을 node로 만들때 생성자를 이용한다.
            - search작업할때 까지는 node로 만들지 않으며 (중복값이 있을수도 있기에)
                insert 직전에 node로 만들어서 삽입한다.
    - delete
        - 삭제하는 경우는 크게 2가지로 나뉜다.
            - 자식노드가 있는 경우와 없는 경우
                - 없는 경우
                    - 그 노드를 그냥 삭제하면 된다.
                    잘 delete시킨다.
                    - 이 단계도 allocator를 쓰는 식으로 바꾸어서 해본다.
                    - map과의 연계를 생각한다.
                    - node단에서 allocator를 쓰는것이 나을 것인가?
                    - tree에 있는 allocator를 쓰게 할 수 있는가?
                        - node를 어떻게 구현하느냐에 따라 달라질수 있을것이라 생각든다.
                - 있는 경우
                    - 후계자를 찾는다.
                        - 왼쪽에서 가장 큰 값 혹은 오른쪽에서 가장 작은값
                        - 왼쪽자식이 없다면 오른쪽에서 구할수 밖에 없다
                        이점을 이용한다.
                    

## 문제 재정의
중복을 허용하지 않는 이진트리으 일종인 Binary Search Tree를 구현한다.
부모노드보다 작으면 왼쪽에 위치하면 크면 오른쪽에 위치한다.
이러한 룰을 통해 search, insert, delete 등의 시간복잡도는 O(nlog n)이 되게 된다.

## 문제해결방법
- 테스트 케이스를 각 사항별로 만들어본다.
- node 필요
    - data
        template <typename T>
    - link
        - left_node
        _ right_node
    - node_cnt

- 동작 필요
    - insert()
        bool insert()
    - find()
        Node find()
    - delete()
        bool

## 검증


## 실행


## 회고


# AVL
## 문제이해


## 문제재정의



## 문제해결방법


## 검증


## 실행


## 회고




# RBT


