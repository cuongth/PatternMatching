#include <iostream>
#include <chrono>
#include "Trie.h"

// Helper function to format duration
template<typename T>
void print_duration(const std::string& prefix, const T& duration) {
    std::cout << prefix << std::fixed << std::setprecision(4)
              << std::chrono::duration<double, std::milli>(duration).count()
              << " ms" << std::endl;
}

int main()
{
    // Start total time measurement
    auto total_start = std::chrono::high_resolution_clock::now();
    Trie trie;
    // Insert patterns into the Trie
    try {
    trie.insert("ana");
    trie.insert("app");
    trie.insert("match");
    trie.insert("is");
    trie.insert("key");
    trie.insert("and");
    trie.insert("patterns");
    } catch (std::bad_alloc& _e) {
        std::cerr << "Failed to insert patterns into a trie" << std::endl;
    }

    // Search for patterns in the text
    std::string text = R"(The quick brown fox jumps over the lazy dog. This is a classic pangram, containing every letter of the English alphabet at least once. It's often used for testing typefaces and keyboards.
However, the world of text extends far beyond simple sentences. Consider a large corpus of scientific papers. Within these documents, one might seek specific keywords like "quantum entanglement," "machine learning algorithms," or "climate change impacts." Identifying these patterns, even with variations in capitalization or surrounding punctuation, is a common application of pattern matching.
Furthermore, analyzing log files from a server requires intricate pattern matching. You might be searching for error codes like "HTTP 404 Not Found," "Database Connection Error," or "Segmentation Fault." Extracting timestamps, IP addresses, or user agent strings from these logs also relies heavily on robust pattern matching techniques, often employing regular expressions for their flexibility and power.
Another example is parsing structured data, such as a large XML or JSON file. Locating specific tags, attributes, or values within nested structures necessitates sophisticated pattern matching. Imagine extracting all "product_id" values from an e-commerce database export or identifying all "customer_name" entries from a user profile dataset.
Finally, in natural language processing, pattern matching is fundamental. Identifying grammatical structures, named entities (like person names or locations), or sentiment indicators within vast amounts of text data is a core task. This involves recognizing complex linguistic patterns that go beyond simple keyword searches, often leveraging advanced algorithms and machine learning models for accurate and efficient analysis.)";
    std::vector<std::pair<std::string, int>> matches;
    trie.search(text, matches);

    try {
    trie.insert("ban");
    trie.insert("man");
    } catch (std::bad_alloc& _e) {
        std::cerr << "Failed to insert patterns into a trie" << std::endl;
    }
    std::string text02 = R"(banak banal banca banco bancs banda bands bandy baned
banes banga bange bango bangs bangy bania banig banjo banka banks banns banty
banus caban ebano Ibans koban leban obang obans ruban unban urban
adman alman amand amang amani amans atman axman caman Coman Cuman emane
Haman human jaman Kuman leman liman manak manas manat manco mands
maneb maned maneh manes manga mange mango mangy mania manic manis
manit maniu manly manna manor manos manse roman saman woman)";
    std::vector<std::pair<std::string, int>> matches02;
    trie.search(text02, matches02);
    // End total time measurement
    auto total_end = std::chrono::high_resolution_clock::now();
    auto total_duration = total_end - total_start;

    // Print the matches
    //for (const auto& match : matches02) {
    //    std::cout << "Pattern '" << match.first << "' found at index " << match.second << std::endl;
    //}

    print_duration("Total execution time: ", total_duration);

    return 0;
}
