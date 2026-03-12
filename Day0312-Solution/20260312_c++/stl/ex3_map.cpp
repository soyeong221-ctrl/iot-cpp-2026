#include <iostream>
#include <map>
using namespace std;

int main() {
    // map은 키-값 쌍으로 데이터를 저장하는 연관 컨테이너. 내부적으로 정렬된 상태로 저장, 키는 고유.
    map<string, int> m;

    m["apple"] = 100;
    m["banana"] = 200;
    m["orange"] = 300;
    //순회 결과
    //apple
    //banana
    //orange

    //iterator를 이용한 순회 (전통적인 방법)
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
    //auto iterator (C++11 이후)
    for (auto it = m.begin(); it != m.end(); ++it) { //
        cout << it->first << " : " << it->second << endl;
    }
    //range-based for (가장 많이 사용)
    for (auto& p : m) { //range-based for (가장 많이 사용)
        cout << p.first << " : " << p.second << endl;
    }
    //구조 분해 방식 (C++17) 
    for (auto& [key, value] : m) {
        cout << key << " : " << value << endl;
    }
    //**std::map** 은 내부적으로 정렬된 상태로 저장

    // 값 찾기
    if (m.find("apple") != m.end())
        cout << "존재";

    // 값 삭제
    m.erase("banana");

    // 키 존재 여부 확인
    if (m.count("banana") == 0) {
        cout << "존재하지 않음.";
    }

    // value 존재 여부 확인(map은 키로 검색하므로, value로 검색하려면 순화해야 함)
    bool valueExists = false;
    for (const auto& p : m) {
        if (p.second == 300) {
            valueExists = true;
            break;
        }
    }

    // 키-값 쌍 추가
    m.insert({ "grape", 400 });


    // 맵 초기화
    map<string, int> m2 = {
        {"kim",90},
        {"lee",85},
        {"park",95}
    };

    // 성적관리예제
    map<string, int> score;

    score["kim"] = 90;
    score["lee"] = 80;
    score["park"] = 95;

    for (auto s : score) {
        cout << s.first << " : " << s.second << endl;

    }

    return 0;
}