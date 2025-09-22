# 🚀 C++14 Docker 환경 실행 가이드

## 📂 프로젝트 구조
```
.
├─ src/
│  ├─ main.cpp
│  ├─ custom_vector.h / custom_vector.cpp
│  ├─ custom_queue.h  / custom_queue.cpp
├─ CMakeLists.txt
├─ Dockerfile.dev
├─ docker-compose.yml
└─ README.md
```

---

## 🐳 Docker 환경 준비

### 1. 개발 이미지 빌드
```bash
docker compose build
```

### 2. 컨테이너 실행 (백그라운드)
```bash
docker compose up -d
```

### 3. 컨테이너 접속
```bash
docker compose exec dev bash
```

---

## ⚙️ 빌드 & 실행

컨테이너 **안에서**:
```bash
# Debug 빌드
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug -j

# 실행
./build/debug/demo
```

---

## 📑 API 명세

### `custom_vector.h`

**헤더 포함**
```cpp
#include "custom_vector.h"
```

**주요 메서드**

| 메서드                                        | 설명                     |
|--------------------------------------------|------------------------|
| `custom_vector()`                          | 빈 벡터 생성                |
| `custom_vector(size_t count, int value=0)` | 초기값으로 채운 벡터 생성         |
| `size()`                                   | 현재 원소 개수 반환            |
| `capacity()`                               | 내부 버퍼 크기 반환            |
| `empty()`                                  | 비었는지 확인                |
| `reserve(size_t n)`                        | 버퍼 용량 확보               |
| `clear()`                                  | 모든 원소 제거 (capacity 유지) |
| `push_back(int v)`                         | 맨 뒤에 원소 추가             |
| `pop_back()`                               | 맨 뒤 원소 제거              |
| `back()`                                   | 맨 뒤 원소 참조              |
| `operator[](i)`                            | i번째 원소 접근              |

**사용 예시**
```cpp
custom_vector v;
v.push_back(10);
v.push_back(20);
for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << "\n";
}
```

---

### `custom_queue.h`

**헤더 포함**
```cpp
#include "custom_queue.h"
```

**주요 메서드**

| 메서드              | 설명         |
|------------------|------------|
| `custom_queue()` | 빈 큐 생성     |
| `size()`         | 원소 개수 반환   |
| `empty()`        | 비었는지 확인    |
| `push(int v)`    | 큐 뒤에 원소 추가 |
| `pop()`          | 큐 앞 원소 제거  |
| `front()`        | 큐 앞 원소 참조  |
| `back()`         | 큐 뒤 원소 참조  |
| `clear()`        | 큐 비우기      |

**사용 예시**
```cpp
custom_queue q;
q.push(1);
q.push(2);
while (!q.empty()) {
    std::cout << q.front() << "\n";
    q.pop();
}
```

---

## 🧹 클린업

### 컨테이너 종료
```bash
docker compose down
```

### 빌드 디렉토리 삭제
```bash
rm -rf build
```
