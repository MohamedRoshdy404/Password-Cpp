#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <string>
#include <functional>  // áÊÌÒÆÉ ÇáÈíÇäÇÊ

std::string generateUniqueID() {
    // ÇáÍÕæá Úáì ÇáæŞÊ ÇáÍÇáí ßÜ ÚÏÏ ÇáäÇäæËÇäíÉ
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

    // ãæáÏ ÇáÃÑŞÇã ÇáÚÔæÇÆíÉ ÈÇÓÊÎÏÇã ãÍÑß ÌíÏ
    std::random_device rd;
    std::mt19937_64 gen(rd());  // äÓÊÎÏã mt19937_64 ááÍÕæá Úáì äÊÇÆÌ ÃÏŞ æÃßÈÑ
    std::uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);

    // ÇÓÊÎÏÇã ÊÌÒÆÉ áÌÚá ÇáÑãÒ İÑíÏ ÈÔßá ÃßÈÑ
    uint64_t random_value = dist(gen);
    std::hash<std::string> hasher;

    // ÊÌãíÚ ÇáÈíÇäÇÊ
    std::stringstream ss;
    ss << std::hex << nanos << random_value;

    // ÊÌÒÆÉ ÇáÑãÒ áÖãÇä ÚÏã ÊßÑÇÑå ÍÊì İí ÍÇáÉ ÊŞÇÑÈ ÇáŞíã
    auto hashed_id = hasher(ss.str());

    // ÊÍæíá ÇáÊÌÒÆÉ Åáì äÕ ÓÏÇÓí ÚÔÑí
    std::stringstream final_ss;
    final_ss << std::hex << hashed_id;

    return final_ss.str();
}

int main() {
    std::string uniqueID = generateUniqueID();
    std::cout << "The Password By Software Engineer Mohamed Roshdy: " << "[ " << uniqueID << " ]" << std::endl;
    system("pause>0");
    return 0;
}
