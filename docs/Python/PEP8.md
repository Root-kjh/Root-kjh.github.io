---
layout: default
title: PEP8 guide
parent: Python
nav_order: 1
---

# PEP8
 
    파이썬 코드 작성을 위한 가이드

# Code Layout

## 들여쓰기

    들여 쓰기 레벨 당 4 개의 공백 사용

연속되는 문장은 괄호를 이용해 수직으로 정렬되거나, 'hanging indent'를 사용해야 한다.

* 좋은 예

```python
# 여는 구분기호로 정렬되는 경우
foo = long_function_name(var_one, var_two,
                      var_three, var_four)

# 추가적인 들여쓰기로 나머지 코드 구분
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)

# hanging indent는 반드시 한 레벨을 추가한다.
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)

# hanging indent의 경우 반드시 4칸 띄어쓰기를 사용하지 않아도 된다.
foo = long_function_name(
  var_one, var_two,
  var_three, var_four)

if 문의 경우 조건문과 if문 내의 문장의 구분을 위해 여러 선택지를 제공한다.

```python
# 추가적인 들여쓰기를 사용하지 않음
if (this_is_one_thing and
    that_is_another_thing):
    do_something()

# 주석을 추가해 조건문과 나머지 코드 구분
if (this_is_one_thing and
    that_is_another_thing):
    # 두 조건문이 만족되면 아래를 실행
    do_something()

# 추가적인 들여쓰기를 통해 조건문과 나머지 코드 구분
if (this_is_one_thing
        and that_is_another_thing):
    do_something()
```

여러 줄 생성자의 닫히는 괄호는 마지막 줄의 공백이 아닌 첫번째 요소 위치에 오거나 마지막 줄에서 생성자가 시작되는 첫번째 열에 위치한다.

```python
my_list = [
    1, 2, 3,
    4, 5, 6,
    ]

result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
    )

my_list = [
    1, 2, 3,
    4, 5, 6,
]

result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
)
```

## Tap or Spaces

    들여쓰기는 space가 권장 된다.

tap은 이미 tap으로 들여쓰기가 사용된 코드에서만 단독으로 사용되며, 파이썬3에서 space와 tap의 혼용을 금한다.

## Maximum Line Length

    모든 코드는 한 줄에 최대 79자까지 쓰는 것을 허용한다.

여러 줄로 길게 표현되는 문장은 괄호를 이용해 여러 행으로 분리해 표현한다.

백슬래시를 사용해 연속 되는 문장의 줄바뀜을 표현하는 것도 좋다.

```python
with open('/path/to/some/file/you/want/to/read') as file_1,\
     open('/path/to/some/file/being/written', 'w') as file_2:
    file_2.write(file_1.read())
```

## Should a line break before or after a binary operator

    PEP은 연산자의 앞에서 줄바꿈을 하는 것을 권장한다.

```python
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
```

## Blank Lines

Top-level 함수와 클래스 정의부는 2개의 빈줄을 이용해 구분한다.

클래스 속 메소드는 한 개의 빈줄을 이용해 구분한다.

## Source File Encoding

파이썬3은 항상 UTF-8 방식을 사용한다.

## Import

임포트는 반드시 행을 분리해 선언한다.

```python
import os
import sys
```

임포트는 절대경로를 이용한 절대 임포트가 권장된다.

```python
import mypkg.sibling
from mypkg import sibling
from mypkg.sibling import example
```

복잡한 레이아웃을 가진 패키지에서는 명시적 상대 임포트가 허용된다.

```python
from . import sibling
from .sibling import example
```

Module level dunder names

모듈레벨의 dunder은(\_\_all__, \_\_future__ 등)은 Docstring 뒤, import 앞에 와야한다.

단, from \_\_future__ import는 docstring 바로 뒤, 그 어떤 코드보다 먼저 위치해야 한다.

```python
For example:

"""This is the example module.
This module does stuff.
"""

from __future__ import baarry_as_FLUFL

__all__ = ['a', 'b', 'c']
__version__ = '0.1'
__author__ = 'Cardinal Biggles'

import os
import sys
```

# String Quotes(따옴표)

문자열 표현 시 따옴표는 자유롭게 사용하되, 가독성을 위해 이스케이프 문자 사용을 피하도록 적절히 따옴표를 선택한다.

세 개의 따옴표를 사용할 때에는 반드시 쌍따옴표를 사용한다. (\"\"\")

# Whitespacce in Expressions and Statements

## Pet peeves

아래와 같은 상황에서 무의미한 공백을 피한다.

* 괄호 안의 양쪽 끝

```python
spam(ham[1], {eggs: 2})
```

* 콤마, 세미콜론, 콜론 바로 앞

```python
if x==4: print x, y; x, y = y, x
```

슬라이스에서 콜론은 우선순위가 낮은 이항연산자와 유사한 방식으로 사용되며, 양쪽에 동일한 공간을 할당해야 한다.

확장된 슬라이스에서 모든 콜론은 같은 크기의 공간이 할당되어야 한다.

피연산자가 누락되었을 경우, 공백 또한 주지 않는다.

```python
ham[1:9], ham[1:9:3]. ham[0:9]. ham[1::3], ham[1:9:]
ham[lower:upper], ham[lower:upper:], ham[lower::step]
ham[lower+offset : upper+offset]
ham[: upper_fn(x) : step_fn(x), ham[:: step_fn(x)]]
ham[lower + offset : upper + offset]
```
* 함수 호출시 인자를 넣기 위한 소괄호의 바로 앞

```python
spam(1)
```

* 리스트, 사전의 인덱스나 슬라이스에 사용되는 대괄호의 바ㅡ로 앞

```python
dct['key'] = lst[index]
```

* 대입 연산자의 앞뒤는 공백을 준다.

```python
x = 1
y = 2
long_variable = 3
```

* 문장의 마지막에 따라오는 공백을 없게 한다.
* 모든 이항연산자 앞뒤로는 공백을 둔다.
* 우선순위가 다른 연산자를 사용할 경우, 낮은 순위의 연산자에 공백을 준다.
* 절대 한 칸을 초과하는 공백은 사용하지 않으며, 이항연산자의 양쪽은 같은 공백을 가진다.

```python
i = i + 1
submitted += 1
x = x*2 - 1
hypot2 = x*x + y*y
c = (a*b) * (a-b)
```

* 키워드 인자나 디폴트 인자에 사용되는 대입연산자는 공백을 사용하지 않는다.

```python
def complex(real, imag=0.0):
    return magic(r=real, i=imag)
```

* function annontation에 사용되는 콜론은 기존 룰을 따르며, '->'는 양 옆에 공백을 한 칸씩 가진다.

```python
def munge(input: AnyStr): ...
def munge() -> AnyStr: ...
```

* argument annontation을 디폴트 변수에 사용할 때, 기존 디폴트 변수에 사용할때의 공백 없는 대입연산자와 다르게 대입연산자 앞 뒤에 공백을 한 칸씩 가진다.

```python
def munge(sep: AnyStr = None): ...
def munge(input: AnyStr, sep: AnyStr = None, limit=1000): ...
```

* 여러 구문이 한 줄에 오는 것은 권장하지 않는다.

```python
if foo == 'blah':
    do_blah_thing()
do_one()
do_two()
do_three()
Rather not:
```

* 가끔 짦은 몸체의 if, for, while 문에서는 여러 구문을 한 줄에 써도 되지만, 절대 여러 줄의 절에서는 한 줄에 쓰면 안된다.
* 또한 긴 줄에서 폴딩은 피해야한다.

```python
Rather not:

if foo == 'blah': do_blah_thing()
for x in lst: total += x
while t < 10: t = delay()
Definitely not:

if foo == 'blah': do_blah_thing()
else: do_non_blah_thing()

try: something()
finally: cleanup()

do_one(); do_two(); th_three(long, argument,
                             list, like, this)
if foo == 'blah': one(); two(); three()
```

# Comments(주석)

주석은 코드가 업데이트 될 때마다 같이 업데이트 해야 한다.

주석은 반드시 완전한 문장형태여야 한다.

주석이 구문이거나 한 문장일 경우, 첫 글자는 대문자를 쓴다. 그러나 첫 단어가 소문자 식별자인 경우 그대로 소문자를 쓴다.

주석이 짧을 경우 마침표가 생략될 수 있다.

마침표 뒤에는 두 칸의 공백을 준다.

주석은 영어로 쓴다.

## Block Comments

    뒤에 따라오는 코드에 대한 설명을 할 때 사용한다.

블록 주석은 뒤에 따라오는 코드와 들여쓰기 수준을 맞춘다.

모든 줄은 # 뒤에 한 칸 공백을 주고 작성한다.

블록 주석의 문단은 # 기호 한줄로 구분한다.

## Inline Comments

    인라인 주석은 한 구문과 같은 줄에 쓰는 주석을 말한다.

인라인 주석은 구문과 적어도 2칸 이상의 공백으로 구분되야 하며, # 기호와 한 칸 공백을 주고 작성을 시작한다.

인라인 주석은 잘 사용되지 않는다.

명백한 상황에서의 주석은 불필요하며, 떄때로 아래와 같은 상황에서는 도움이 된다.

```python
x = x + 1        # Compensate for border
```

## Documentation String

public 모듈, 함수, 클래스, 메소드에 대해서 Docsstring을 작성하는게 좋다.

non-public 메소드는 Dqocstring이 필요없다. 다만 메소드가 무슨 역할을 하는지 주석을 작성하는 것이 좋다.

def 문장 바로 아래줄에 위치하는 것이 좋다.

Docstring 마지막 줄은 \"\"\" 기호 한줄로 끝낸다.

```python
"""Return a foobang
Optional plotz says to frobnicate the bizbaz first.
"""
```

# Naming Conventions

    파이썬 코드의 명명규칙은 매우 복잡하기에 완전히 일정하게 정하지 않는다.

    기존 작성된 코드는 그 코드의 명명법을 따르도록 하고, 앞으로 작성될 코드에 아래 규칙을 따르도록 한다.

## Overriding Principle

    사용자에게 public API로 보여지는 이름은 그 구현보다 사용법을 나타내도록 명명하는 것이 좋다.

## Names to Avoid

한 글자 변수명으로 l, O, I를 사용하지 않는ㄴ다.

I를 써야한다면 L을 쓰도록 한다.

## Package and Module Names

모듈이름은 짧아야 하고 모두 소문자를 사용하며, 가독성을 위해 언더스코어가 쓰일 수 있다.

패키지 이름도 짧아야 하고 모두 소문자를 사용하며, 언더스코어를 사용하지 않는다.

## Class Names

    CapWords 방식을 따른다.

인터페이스가 정의 되어 있거나, callable로서 우선적으로 사용되는 경우, 함수명명법이 대신 사용된다.

## Type variable names

    짧은 CapWords 방식을 사용한다.(T, AnyStr, Num)

covariant or contravariant임을 나타내기 위해 변수의 접미사로 _co or _contra가 사용된다.

```python
from typing import TypeVar

VT_co = TypeVar('VT_co', covariant=True)
KT_contra = TypeVar('KT_contra', contravariant=True)
```

## Exception Names

    예외도 클래스이기 때문에 클래스 명명규칙을 따른다. 그리고 접미사 'Error'를 붙인다.(실제 그 예외가 에러일 경우)

## Global Variable Names

    이 규칙은 함수에 적용되는 것과 동일하다.

'from M import *'을 사용하도록 설계된 모듈에서는 '\_\_all\_\_'을 사용해 다른 모듈에서 사용되는 것을 막거나, 예전 규칙인 언더스코어를 이름 앞에 붙여 사용해 'non-public'임을 나타내야한다.

## Function Names

    언더스코어로 단어를 구분한다.

## Function and method arguments

인스턴스 메소드의 첫 인수로 반드시 self를 쓴다.

클래스 메소드의 첫 인수로는 반드시 cls를 쓴다.

인수명이 키워드와 충돌될 경우, 인수명 뒤에 언더스코어를 붙여 사용한다. (ex : class_)

가장 좋은 방법은 충돌이 없게끔 동의어로 이름을 짓는 것이다.

## Method Names and Instance Variable

    함수명명규칙을 따른다.

non-public 메소드, 인스턴스 변수에는 언더스코어 하나를 붙인다.

서브클래스와의 충돌을 피하기 위해 언더스코어 2개를 붙여 파이썬 이름 managling 규칙을 따르도록 한다.

파이썬은 다음과 같은 managling 규칙을 따른다.

    만약 'Foo' 클래스 안에 '__a'인 어트리뷰트가 있다면 'Foo.__a'의 형태로 접근이 불가능하다.
    일반적으로 이름 앞 언더스코어 2개를 붙이는 방식은 주로 서브클래스로 사용되도록 디자인 된 클래스의 어트리뷰트와의 이름충돌을 막기 위해 사용한다.

## Constants

삼수는 주로 모듈레벨에서 정의되며 언더스코어를 이용한 대분자 표기법을 사용한다.

예로 MAX_OVERFLOW, TOTAL과 같은 방식으로 표기한다.

## Designing for inheritance

항상 클래스의 메소드와 어트리뷰트를 public으로 할지 non-public으로 할지 정해라.

만약 불확실하다면 non-public으로 정해라.

* public 어트리뷰트 : 관련 없는 클라이언트가 직접 사용 가능

* non-public 어트리뷰트 : 서드파티에 의해 사용되지 않도록 의도된 것이나 수정, 삭제가 가능하다.


    파이썬은 private라는 말을 사용하지 않는다. 파이썬에 진짜 private한 어트리뷰트는 없다.

다른 종류의 어트리뷰트로는 서브클래스 API가 있다.(protected)

단순한 데이터 어트리뷰트는 직접 접근을 허용한다.

properties는 새로운 스타일의 클래스에서만 작동한다.

Caching과 같은 부작용은 일반적으로 괜찮지만, 부작용이 없는 기능적인 일을 유지하도록 시도하는것이 좋다.

계산적으로 상당한 작동을 요구하는 properties를 사용하는 것을 피하도록 한다.

만약 클래스가 서브클래스화 되는 것이 고려될 때, 서브클래스에서 사용하길 원하지 않는 속성을 가지고 있다면, 이름 앞에 두 개의 언더스코어를 활용하는 네이밍과 이름 끝에는 언더스코어를 작성하지 않는것을 고려하도록 한다.

## Public과 내부 인터페이스

이전버전과의 호환성 보장은 오직 public 인터페이스에게만 적용한다.

이전 버전과의 호환성 보장을 하지 않는 한 문서가 그들을 임시적 혹은 내부의 인터페이스라고 선언하지 않는 한 문서화된 인터페이스는 public을 고려한다.

모듈은 public API 내부에서 \_\_all\_\_ 속성을 사용해 선언한다.

내부 인터페이스는 하나의 언더스코어를 사용해 접두어를 붙여야한다.

어느 네임스페이스(패키지 모듈 or 클래스)가 내부로 고려된다면, 해당하는 인터페이스도 내부로 고려된다.

# 프로그래밍 권장사항

파이썬의 다른 인터프리터(PyPy, Jython, Cython 등)에 모두 호환되는 코드가 작성되어야 한다.

None과 같이 개체에 대한 비교는 반드시 is 혹은 is not과 함께 수행되어야 한다.

다양한 비교를 사용하여 순서 지정 연산을 구현할 때, 특정 코드만 사용하여 다른 코드를 사용하는 대신 6가지 연ㅅ산을 모두 구현하는 것이 가장 좋다.(이해안됨)

람다 표현식을 식별자에 직접 바인드하는 할당문 대신 항상 def 문을 사용하도록 한다.

BaseException보다 Exception으로부터 예외를 얻도록 한다.

예외 체인을 적절히 사용하도록 한다.

예외를 선정할 때, 가능하다면 except: 보다 특정 예외를 언급하도록 한다.

bare except: 절은 컨트롤C를 사용하여 프로그램을 중단시키는 것을 어렵게 만드는 SystemExit와 KeyboardInterrupt 예외를 잡을 수 있고, 다른 문제를 숨길 수 있다.

    만약 사용자가 모든 예외를 잡길 원한다면 except Exception: 을 사용한다.

모든 try/except 구문에 대해, try 구문의 절대적인 수를 최소한으로 제한하도록 한다.

리소스가 코드의 특정 세션에 위치할 때, 이것이 사용이후 신뢰성 있게 정리되는 것을 보장하도록 with 혹은 try/finally 구문을 적용해야한다.

return 구문에서 일관성을 유지하도록 한다.

    * 함수에 있는 모든 return 구문은 반드시 표현식을 반환하거나, 없어야한다.

    * 만약 어떤 return 구문이 표현식을 반환했다면, return 구문이 반환되는 값이 없는 곳에서는 return None을 명시하고 함수의 끝에(도달할 수 있다면) explitict return 구문이 존재해야 한다.

문자열 모듈 대신 메서드를 사용하도록 한다.

* 좋은 예
```python
if foo.startswith("bar"):
```

* 나쁜 예
```python
if foo[:3]=="bar":
```

시퀀스(문자열, 리스트, 튜플)에 대해 비어있는 시퀀스는 false 라는 것을 이용한다.

```python
if not seq:
if seq:
```