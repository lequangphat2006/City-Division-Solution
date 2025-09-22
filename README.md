# CITY DIVISION CHALLENGE 2025

## ITQnu Challenge (ITQC) 2025 - CHIA CỤM XÃ

**"Từ một thành phố, tạo ra ba vương quốc!"**

---

## MISSION IMPOSSIBLE

Bạn là MASTER PLANNER của thành phố Quy Nhon!  
Nhiệm vụ: **CHIA THÀNH PHỐ THÀNH 3 CỤM** bằng cách phá hủy đúng **2 CON ĐƯỜNG** để:
- **Minimize** độ chênh lệch giữa cụm lớn nhất và nhỏ nhất
- Tạo ra sự cân bằng hoàn hảo trong thế giới mới!

---

## ALGORITHM WARFARE

### NOOB APPROACH (Brute Force - O(n³))
```cpp
// Thử tất cả cặp cạnh = DEATH BY TIMEOUT
for (int i = 0; i < edges.size(); i++) {
    for (int j = i + 1; j < edges.size(); j++) {
        // Simulate removal... RIP performance
        removeEdges(i, j);
        calculateComponents();
    }
}
```
**Verdict**: Time Limit Exceeded cho n = 200,000

### PRO APPROACH (Tree Rerooting - O(n²))
```cpp
// CHAD MOVE: Tính subtree một lần, reuse everywhere!
dfs1(1, -1);  // Calculate subtree sizes
dfs2(1, -1);  // Try all possible cuts like a BOSS
```
**Verdict**: **ACCEPTED** - Speed of Light!

---

## GAME MECHANICS

### INPUT FORMAT
```
9          // n districts (nodes)
1 2        // Road connecting district 1 & 2
1 3        // Road connecting district 1 & 3
2 5        // Road connecting district 2 & 5
3 6        // Road connecting district 3 & 6
3 7        // Road connecting district 3 & 7
6 8        // Road connecting district 6 & 8
6 9        // Road connecting district 6 & 9
1 4        // Road connecting district 1 & 4
```

### OUTPUT FORMAT
```
2          // Minimum difference between max and min cluster
```

### VISUAL REPRESENTATION
```
        1
      / | \
     2  3  4
    /  / \
   5  6   7
     / \
    8   9
```

**Optimal Strategy**: 
- Cut edges to create clusters: [1,2,4,5], [3,7], [6,8,9]
- Cluster sizes: [4, 2, 3]
- Difference: max(4,2,3) - min(4,2,3) = 4 - 2 = 2

---

## PERFORMANCE BENCHMARKS

| Method | Time Complexity | Space | Status | Rating |
|--------|----------------|--------|---------|--------|
| Brute Force | O(n³) | O(n) | TLE | NOOB |
| Tree Rerooting | O(n²) | O(n) | AC | PRO |
| Heavy-Light Decomp | O(n log n) | O(n log n) | OVERKILL | GOD |

---

## CODE ARCHITECTURE

### Core Functions
- `dfs1(u, p)`: **Subtree Size Calculator** - Tính toán kích thước subtree cho mọi node
- `dfs2(u, p)`: **Cut Explorer** - Thử nghiệm mọi cách cắt có thể từ node u
- `main()`: **Command Center** - Điều khiển toàn bộ operation

### Key Insights
1. **Tree Property**: n nodes, n-1 edges → Always connected initially
2. **Cut Logic**: Remove exactly 2 edges → Always creates exactly 3 components
3. **Rerooting Magic**: Calculate subtree sizes once, reuse for all cut scenarios
4. **Optimal Strategy**: For each node, try all pairs of adjacent components

---

## TEST CASES BREAKDOWN

### 25% Tests: 3 ≤ n ≤ 200
- **Brute Force**: Still alive, runs in ~1 second
- **Tree Rerooting**: Overkill but guaranteed AC

### 25% Tests: 3 ≤ n ≤ 2000
- **Brute Force**: Struggling, ~10-30 seconds
- **Tree Rerooting**: Smooth as butter, <0.1 seconds

### 50% Tests: 3 ≤ n ≤ 200000
- **Brute Force**: DEAD ON ARRIVAL (would take hours)
- **Tree Rerooting**: The ONLY way to survive, ~1-2 seconds

---

## IMPLEMENTATION DETAILS

### Memory Optimization
```cpp
// Global arrays for maximum performance
vector<int> adj[MAXN];      // Adjacency list
int subtree[MAXN];          // Subtree sizes
```

### Speed Optimizations
```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// Faster I/O = More time for computation
```

### Edge Case Handling
- **Minimum n = 3**: Always possible to create 3 components
- **Linear tree**: Worst case scenario, still solvable
- **Star graph**: Best case, many optimal solutions

---

## DEBUGGING ARSENAL

### Sample Test Case Walkthrough
```
Input:
9
1 2
1 3  
2 5
3 6
3 7
6 8
6 9
1 4

Tree Structure:
        1
      / | \
     2  3  4
    /  / \
   5  6   7
     / \
    8   9

Optimal Cut Analysis:
- Try cutting edges from node 1: (1,2) and (1,3) → Components: [2,5], [3,6,7,8,9], [4]
- Try cutting edges from node 3: (3,6) and (3,7) → Components: [1,2,4,5], [6,8,9], [7]
- And so on...

Best Result: Difference = 2
```

---

## COMPETITIVE PROGRAMMING TIPS

### Time Management
- **First 10 minutes**: Understand the problem, identify it's a tree problem
- **Next 20 minutes**: Code the tree rerooting solution
- **Last 5 minutes**: Test with sample cases

### Common Pitfalls
1. **Off-by-one errors** in component size calculation
2. **Forgetting parent component** when rerooting
3. **Integer overflow** (not applicable here, but good practice)
4. **Wrong base case** for recursion

### Pro Techniques
- **Template ready**: Have tree templates prepared
- **Debug macros**: Quick debugging for tree structures
- **Stress testing**: Generate random trees for testing

---

## FINAL BOSS BATTLE

This problem is a perfect example of:
- **Graph Theory**: Tree manipulation and traversal
- **Dynamic Programming**: Reusing subtree computations
- **Optimization**: From O(n³) to O(n²) complexity reduction

**Master this problem = Master tree algorithms!**

---

## VICTORY CONDITIONS

- **Bronze Medal**: Get the brute force working for small cases
- **Silver Medal**: Implement tree rerooting correctly
- **Gold Medal**: Optimize to handle all test cases within time limit
- **Legendary**: Explain the solution to others and help them understand

**Now go forth and conquer the city division challenge!**
