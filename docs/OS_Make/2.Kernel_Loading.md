# Kernel Loading
> MBR 영역의 512Byte는 OS를 실행시키기에 작은 공간이기 때문에 하드디스크의 MBR영역 다음 영역의 OS를 불러와 실행시킨다.


### boot.asm

```assembly
[org 0]
[bits 16]
    jmp 0x7c0:start

start:
    mov ax, cs
    mov ds, ax
    mov es, ax
    
    mov ax, 0xB800
    mov es, ax
    mov di, 0
    mov ax, word[msg]
    mov cx,0x7FF

paint:
    mov word[es:di], ax
    add di, 2
    dec cx
    jnz paint

 read:
    mov ax,0x1000
    mov es, ax
    mov bx, 0           ;[es:bx]Buffer Address Pointer

    mov ah, 2           ;Read Sectors From Drive 옵션 지정
    mov dl, 0           ;Drive
    mov ch, 0           ;Cylinder
    mov dh, 0           ;Head
    mov cl, 2           ;Sector
    mov al, 1           ;Sectors To Read Count

    int 0x13            ;Read

    jc read
    jmp 0x1000:0000

msg db '.',0x17

times 510-($-$$) db 0

dw 0xAA55
```

[인터럽트 0x13의 옵션](https://en.wikipedia.org/wiki/INT_13H#INT_13h_AH=02h:_Read_Sectors_From_Drive)

### kernel.asm

```assembly
[org 0]
[bits 16]

start:
    mov ax, cs
    mov ds, ax

    mov ax, 0xB800
    mov es, ax
    mov di, 0

print:
    mov edi, 0
    mov byte[es:edi], 'D'
    inc edi
    mov byte[es:edi], 0x16
    inc edi
    
    mov byte[es:edi], 'r'
    inc edi
    mov byte[es:edi], 0x16
    inc edi
    
    mov byte[es:edi], '_'
    inc edi
    mov byte[es:edi], 0x16
    inc edi
    
    mov byte[es:edi], 'K'
    inc edi
    mov byte[es:edi], 0x16
    inc edi
```