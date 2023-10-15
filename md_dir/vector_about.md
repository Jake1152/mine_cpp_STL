# Vector

//generic template
- vector란?
	- dynamic array
		array처럼 element에 대한 연속적인 저장 위치를 사용한다.
		element접근에 대해 일반 포인터처럼 data size에 따라서 pointer arithmetic을 쓴다.
		하지만 차이점으로 저장공간이 컨테이너에 의해 자동으로 처리되어서 크기가 동적으로 바뀔 수 있다.
	
	- 내부적으로 벡터는 동적으로 할당된 배열을 사용하여 요소를 저장한다.
		새 요소가 삽입 될때 크기를 느릭 위해 배열을 재할당해야할 수 있다.
		dynamic structure란 사이즈가 동적으로 바뀜을 의미한다.
		
	- array이면서 capacity보다 큰 값이 들어오면 더 커진다.
	- method (member function이라고 하는데 맞는가? 범위가 특정상황에 좁혀져 있지 않는가?)
		- push_back()
		- 


<!---
TO DO
- dynamic structure란?
- generic programming이란?
- template programming이란?
- meta template이란?
- template이란?
- OOP란?
- template 타이즈란?
- allocator란?
- iterator란?
- explicit란?
- Member types
-->
