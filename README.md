# PatternMatching
Pattern Matching in Strings using Trie Data Structure in C++.   

- Build the Trie: Create a Trie and insert all the patterns into it.   

- Text Processing: Iterate through the text and for each character, check if it is present in the Trie.   

- Pattern Matching: If we reach a node in the Trie that corresponds to the end of a pattern, it means we have found a match.   

<table>
    <tr>
        <td><b>amd ryzen 3 1200 quad-core</b></td>
        <td>raw pointer</td>
        <td>std::unique_ptr</td>
    </tr>
    <tr>
        <td><b>1st</b></td>
        <td>2.0717 ms</td>
        <td>2.5244 ms</td>
    </tr>
    <tr>
        <td><b>2nd</b></td>
        <td>2.1714 ms</td>
        <td>2.2366 ms</td>
    </tr>
    <tr>
        <td><b>3rd</b></td>
        <td>2.0790 ms</td>
        <td>2.2211 ms</td>
    </tr>
</table>

There are 2 versions: using raw pointers (with destructors) and smart pointers (without destructors). The "raw pointers" version has better performance. The difference becomes more pronounced with:

    - More patterns are inserted.
    - Longer string.   


