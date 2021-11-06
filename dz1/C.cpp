#include <iostream>
#include <utility>
//#include <unordered_map>
#include <map>


/*there are 3 possible alternatives:            with extra conditions each:
    3 x in a row with no 3 o in a row               #{x} = #{o} + 1
    3 o in a row with no 3 x in a row               #{o} = #{x}
    nor x nor o make a row.                     5 = #{x} = #{o} + 1
*/

typedef std::pair<int,int> pair;

int main() {
    //std::unordered_map <pair, int> field; problems with hash function
    std::map <pair, int> field;
    return 0;
}