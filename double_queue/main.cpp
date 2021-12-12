#include <iostream>
#include <set>

int main() {
    // множество, моделирующее очередь клиентов,
    // где каждый элемент множества представлен в виде пары "приоритет:номер"
    std::set<std::pair<int, int>> queue;
    std::set<std::pair<int, int>>::iterator it;
    int state; // вводимый код
    std::string result;

    while(std::cin >> state) {
        // добавление клиента в очередь
        if (state == 1) {
            int client, priority;
            std::cin >> client >> priority;
            queue.insert(std::make_pair(priority, client));
        }
        // обслуживание клиента с наивысшим приоритетом
        else if (state == 2) {
            if (queue.empty())
                result += "0\n";
            else {
                it = std::prev(queue.end());
                result += std::to_string(it->second);
                result += "\n";
                queue.erase(it);
            }
        }
        // обслуживание клиента с самым низким приоритетом
        else if (state == 3) {
            if (queue.empty())
                std::cout << "0\n";
            else {
                it = queue.begin();
                result += std::to_string(it->second);
                result += "\n";
                queue.erase(it);
            }
        }
        // завершение работы системы
        else if (state == 0)
            break;
    }

    std::cout << result;

    return 0;
}
