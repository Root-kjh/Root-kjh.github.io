---
layout: default
title: 2020년 회고
parent: 회고록
nav_order: 2
---

# 활동

### 토이 프로젝트 

처음 목표였던 Spring, Spring Boot, Django, Nodejs 프레임워크 중, Spring, Spring Boot, Django와 추가로 Flask 프레임워크까지 사용해보았다.

프로젝트를 진행하면서 처음의 목표였던 성능, 효율성에 이어 코드의 가독성, 확장성까지 따져가며 점점 더 개발자스러운 코드를 내놓기 시작했다.

개발을 하다보니 확실히 Restful Api가 좋다고 느꼈다.

Django 프로젝트는 그냥 백엔드에서 프론트까지 다 내놓는 방향으로 진행했는데 뭔가 깔끔하지 않아 결국 Rest Api로 분리하기로 결정했다.

아직 프로젝트가 끝난건 아니지만, Django프레임워크는 아직까진 다른 프레임워크에 비해 효자라고 느낀다. 프레임워크안에 기능이 다 있어서 그런지 자잘한 버그가 없다.

그리고 Flask는 초반엔 여러 모듈을 추가해 쓰면서 정말 좋다고 느꼈다.

하지만 테스트 코드를 작성하면서 관리가 되어있지 않은 모듈의 문제로 테스트가 되지 않는 문제가 발생했다. (내가 잘 못쓰는 것일수도 있지만 아마 모듈 문제가 맞다 싶다.) 검색해보니 나와 같은 문제를 겪은 사람이 있었고, 기능을 추가할 때마다 모듈의 충돌을 모두 검사하며 개발을 하셨다. 나도 그렇게 해야할 것 같다.

가장 먼저 완성했던 토이 프로젝트 RecruitList는, 처음에 했던 만큼 나중가서 보니 코드가 맘에 들지 않아 갈아엎었다.

당시 Spring Boot를 사용하지 않고, 스프링의 내부 동작 과정을 자세히 알기 위해 그냥 Spring을 사용했는데 그게 패착이었다.

dependency를 하나 추가할 때마다 버전을 맞춰서 충돌이 나지 않는지 확인해야했다.(이 점 때문에 Flask 버그를 보며 Spring과 많이 비슷하다고 느꼈다.) 이는 물론 코드를 리팩토링 할때도 적용됐다.

어찌저찌 해서 리팩토링은 끝냈지만 spring security가 제대로 동작하지 않아 고쳐야 한다.

TodoList 프로젝트는 Spring Boot로 금방 끝내고, 이것도 나중가서 보니 코드가 맘에들지 않아 리팩토링 하려 했으나, 앞서 말한 버그에 곧 압사할것만 같은 관계로 일단 keep 해두었다.

### 알고리즘 풀이

가끔 심심할때면 백준 사이트에 들어가 알고리즘 문제를 조금씩 풀기도 했다.

랭크는 5000등, solved.ac 사이트에서 실버1이라는 티어를 받았다. 더 노력해서 롤티어만큼 플레티넘은 찍는게 목표다.(21년 3월에 레이팅 계산 시스템이 바뀌면 티어가 골드5로 바뀐다고 한다. ㅎㅎ)

# 좋았던점

여러 프레임워크를 경험하며 각 프레임워크의 사용법과 장단점을 익히고, 다른 사람들의 코드를 보며 많은것을 깨달았다.

토이프로젝트가 모두 끝나면 맘에 드는 프레임워크를 골라 더 수준높은 프로젝트를 진행 할 수도 있을것같다. 

# 아쉬운점

끝없는 삽질과 피드백없는 개발의 반복 끝에 매너리즘에 빠졌다.

계속 새로운것을 배워나가며, 재미에 빠졌던 학생때의 나는 사라지고 그저 의무적으로 해야한다는 생각만으로 코드를 짜는 그저그런 사람이 되어버렸다.

학습에 대한 재미를 잃은만큼 학습 속도도 많이 더뎌졌고, 이미 완성된 프로젝트도 맘에 들지 않아 코드 리팩토링을 계속 진행하다보니 매일 버그나 고치는 나날이 반복됐다.

# 개선사항

사실 몇주째 막히는 부분은 누군가에게 물어보고싶지만 주변에 알려줄만한 사람이 없어 혼자 해결해야한다.

궁극적으로 모든 문제를 해결하려면 QA테스터에서 벗어나 백엔드 개발자로 자체 서비스 회사로 이직해 사람들이 이용하는 웹을 직접 Develop 하고, 모르는건 잘하는 사람들에게 물어보는 등 커뮤니케이션을 통해 열정을 다시 되찾아야 한다고 생각한다.

하지만 실력이 있어야 회사에서 뽑든말든 할테니 일단 묵묵히 하던 토이프로젝트를 계속하며 이직기회를 열심히 노려보는게 최선일듯하다.

# 총평

전체적으로 암울한 한해였다. 여러 프로젝트를 벌려놓고, 열심히 공부하려 했으나 잘 되지 않았다. 또, 군사훈련에 코로나까지 곂쳐 스트레스를 풀 수도 없는(전 국민이 마찬가지겠지만) 상황이 닥쳐 이도 저도 애매하게 돼버렸다.

한가지 다행인건 동시에 진행중인 여러 프로젝트, Flask, Django 프로젝트가 곧 끝날 기미가 보이고, Nodejs로 진행하는 프로젝트도 아이디어만 있으면 금방 끝낼 것 같다.

결론은 없다. 그냥 하던거나 잘하자

# 추가

새벽2시에 공부하려다 너무 답답해서 쓴 회고라 봤을 때 앞뒤 안맞고, 맥락이 뒤틀려 있을 수 있다.(볼 사람이 있을지는 모르겠다.)

쓰다보니 회고보단 한탄에 가까웠던 것 같다.

아무쪼록 2021년은 코로나도 끝나고, 개발자로 이직도 성공해서 유쾌한 한해가 되었으면 좋겠다.