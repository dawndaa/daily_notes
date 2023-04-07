# include "cachelab.h"
# include <unistd.h>
# include <getopt.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <stdbool.h>
typedef unsigned long long int mem_addr_t;
/*cache hit: 命中
 *cache miss: 未命中
 *cache eviction: 缓存驱逐 覆盖掉原有的某个块
 *
 *operations:
 * I: 指令加载
 * S: 数据存储 
 * M: 数据修改 先读取 后存储 
 * L: 数据读取
 * 格式[space] operation address, size
 * address 64位十六进制地址
 * size 此次访问的字节数l
 * 
 *存储器地址有m位，set index有s位，数据块有b位，tag有t位 
 *t = m - (s + b)
 */
int cnt = 0;
typedef struct cache_line {
    bool v;
    mem_addr_t tag;
    int tMark;    
} cache_line;

void judge(cache_line** cache, mem_addr_t tag, int s_id, int E, int* hit, int* miss, int* evic){
    ++cnt;
    bool all_true = true, tag_eq = false;
    int t = cache[s_id][0].tMark, id = 0, false_id = 0;
    for (int i = 0; i < E; ++i) {
        if (cache[s_id][i].v == true && cache[s_id][i].tag == tag && tag_eq == false) {
            *hit += 1;
            printf("hit ");
            cache[s_id][i].tMark = cnt;
            tag_eq = true;
        } 
        else if (cache[s_id][i].v == false) {
            all_true = false;
            false_id = i;
        }
        if (cache[s_id][i].tMark < t) {
            t = cache[s_id][i].tMark;
            id = i;
        }  
    }
    if (all_true && tag_eq == false) {
        *miss += 1;
        *evic += 1;
        printf("miss eviction ");
        cache[s_id][id].tag = tag;
        cache[s_id][id].tMark = cnt;
    }
    else if (all_true == false && tag_eq == false){
        *miss += 1;
        printf("miss ");
        cache[s_id][false_id].v = true;
        cache[s_id][false_id].tag = tag;
        cache[s_id][false_id].tMark = cnt;
    }
    else ;
}
void L_judge(cache_line** cache, mem_addr_t tag, int s_id, int E, int* hit, int* miss, int* evic) {
    
}
int main(int argc, char** argv){
    int hit_cnt = 0, miss_cnt = 0, evic_cnt = 0;
    int opt = 0, s = 0, E = 0, b = 0, m = 64;
    char* t = (char*)malloc(20 * sizeof(char));

    while ((opt = getopt(argc, argv, "s:E:b:t:")) != -1){
        switch(opt) {
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                t = optarg;
                break;
            default:
                printf("wrong argument\n");
                break;
        }
    }

    char* path = (char*)malloc(80 * sizeof(char));
    getcwd(path, 80);
    strcat(path, "/");
    strcat(path, t);
    printf("%d %d %d %d %s\n", s, E, b, m, path);

    FILE* pFile;
    pFile = fopen(path, "r"); 
    char identifier;
    mem_addr_t address;
    int size;
    int S = 1 << s;

    cache_line** cache = (cache_line**)malloc(S * E * sizeof(cache_line));
    for (int i = 0; i < S; ++i) {
        cache[i] = (cache_line*)malloc(E * sizeof(cache_line));
        for (int j = 0; j < E; ++j) {
            cache[i][j].v = false;
            cache[i][j].tag = 0;
            cache[i][j].tMark = 0;
        }
    }
    while (fscanf(pFile, " %c %llx,%d", &identifier, &address, &size) > 0) {  
        bool isI = false;
        mem_addr_t tag = address >> (b + s);
        int sId = (address << (m - s - b)) >> (m - s);
        if (identifier == 'I') {
            isI = true;
            continue;
        }
        else {
            if (!isI) {
                printf("%c %llx, %d ", identifier, address, size);
                printf(" tag: %lld s_id: %d ", tag, sId);
            }
            if (identifier == 'S') {
                judge(cache, tag, sId, E, &hit_cnt, &miss_cnt, &evic_cnt);
            }
            else if (identifier == 'L') {
                judge(cache, tag, sId, E, &hit_cnt, &miss_cnt, &evic_cnt);
            }
            else if (identifier == 'M') {
                judge(cache, tag, sId, E, &hit_cnt, &miss_cnt, &evic_cnt);
                judge(cache, tag, sId, E, &hit_cnt, &miss_cnt, &evic_cnt);
            }
            else printf("error operation!");
            printf("\n");
        }
         
    }


    printSummary(hit_cnt, miss_cnt, evic_cnt);
    return 0;
}
