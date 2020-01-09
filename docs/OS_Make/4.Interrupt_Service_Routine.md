# Interrupt Service Routine

### Interrupt
1.  Hardware Interrupt
>프로그램 실행 중 하드웨어로부터 받는 신호
2.  Software Interrupt
>INT (n) 명령어로 소프트웨어에서 보내는 신호
3.  Exception
>프로그램 실행 중 특정 조건에 만족하는 상황에 발생

### PIC(Programmable Interrupt Controller)
>메인보드 전체의 하드웨어 인터럽트를 관리하는 칩(요즘은 메인보드 칩셋에 로직화되어 포함되어 있다.)

각 PIC는 8개의 IRQ(Interrupt Request Line)핀을 갖고 있다.

IRQ는 마스터/슬레이브 형식으로 한 CPU를 기준으로 한 컨트롤러가 연결되어 있고, 그 컨트롤러에 하나의 다른 컨트롤러가 연결되어 있다.

그리고 이 연결은 INT라는 핀으로 이루어져 있다.

![CPU and Master/Slave PIC](https://t1.daumcdn.net/cfile/tistory/2474A93653FA924D12)

### PIC behavior when an interrupt occurs

* Interrupt on master PIC
    1. 마스터 PIC는 자신의 INT핀에 신호를 실어 CPU의 INT핀에 신호를 준다.