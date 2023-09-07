//Assumptions: the first dictionary is already sorted, the second one will be merged and sorted.
//Algorithm Analysis are in pdf
#include <stdio.h> 
#include <string.h> 
#define SIZE 1000 
struct Dictionary { 
    char english[50]; 
    char turkish[50]; 
}; 
int next[SIZE]; 
void Insertion(struct Dictionary dict[], struct Dictionary entry, int head) { 
    int now = head; 
    int pre = -1; 
    while (now != -1 && strcmp(dict[now].english, entry.english) < 0) { 
        pre = now; 
        now = next[now]; 
    } 
    int size = 0; 
    for (size = 0; dict[size].english[0] != '\0'; size++) {} 
    if (pre == -1) { 
        next[size] = head; 
        head = size; 
    } else { 
        next[pre] = size; 
        next[size] = now; 
    } 
    dict[size] = entry; 
    for (int i = 0; dict[i].english[0] != '\0'; i++) { 
        for (int j = i+1; dict[j].english[0] != '\0'; j++) { 
            if (strcmp(dict[i].english, dict[j].english) > 0) { 
                struct Dictionary temp = dict[i]; 
                dict[i] = dict[j]; 
                dict[j] = temp; 
            } 
        } 
    } 
} 
 
 
void Algorithm1(struct Dictionary dict1[], struct Dictionary dict2[], struct Dictionary result[], int index) { 
    int i, j; 
    int head = -1; 
    for (i = 0; dict1[i].english[0] != '\0'; i++) { 
        Insertion(result, dict1[i], head); 
        head = 0; 
    } 
     
    for (j = 0; dict2[j].english[0] != '\0'; j++) { 
        Insertion(result, dict2[j], head); 
        head = 0; 
    } 
} 
 
void Algorithm2(struct Dictionary dict1[], struct Dictionary dict2[], struct Dictionary result[], int index) { 
    int i = index, j = index, k = 0; 
    while (dict1[i].english[0] != '\0' || dict2[j].english[0] != '\0') { 
        if (dict1[i].english[0] == '\0') { 
            result[k] = dict2[j]; 
            j++; 
        } else if (dict2[j].english[0] == '\0') { 
            result[k] = dict1[i]; 
            i++; 
        } else if (strcmp(dict1[i].english, dict2[j].english) < 0) { 
            result[k] = dict1[i]; 
            i++; 
        } else { 
            result[k] = dict2[j]; 
            j++; 
        } 
        k++; 
    } 
} 
int main() { 
    struct Dictionary dict1[] = {{"ab", "e"}, {"b", "a"}, {"d", "q"}, { "", "" }}; 
    struct Dictionary dict2[] = {{"ac", "q"}, {"c", "q"}, {"z", "s"}, { "", "" }}; 
    struct Dictionary result[SIZE]; 
    Algorithm1(dict1, dict2, result, 0); 
    printf("Algorithm 1: \n"); 
    for (int i = 0; result[i].english[0] != '\0'; i++) { 
        printf("%s: %s\n", result[i].english, result[i].turkish); 
    } 
    struct Dictionary result2[SIZE]; 
    Algorithm2(dict1, dict2, result2, 0); 
    printf("Algorithm2: \n"); 
    for (int i = 0; result2[i].english[0] != '\0'; i++) { 
        printf("%s: %s\n", result2[i].english, result2[i].turkish); 
    } 
    return 0; 
}

/*
DEFINE SIZE as 1000

DEFINE struct Dictionary
    english as array of characters with size 50
    turkish as array of characters with size 50
END STRUCT

DEFINE next as array of integers with size SIZE

FUNCTION Insertion(dict[], entry, head)
    SET now as head
    SET pre as -1
    
    WHILE now != -1 AND strcmp(dict[now].english, entry.english) < 0
        SET pre as now
        SET now as next[now]
    END WHILE
    
    SET size as 0
    FOR size from 0 to SIZE - 1
        IF dict[size].english[0] == '\0' THEN
            BREAK
        END IF
    END FOR
    
    IF pre == -1 THEN
        SET next[size] as head
        SET head as size
    ELSE
        SET next[pre] as size
        SET next[size] as now
    END IF
    
    SET dict[size] as entry
    
    FOR i from 0 to SIZE - 1
        FOR j from i+1 to SIZE - 1
            IF dict[i].english[0] == '\0' OR dict[j].english[0] == '\0' THEN
                BREAK
            END IF
            IF strcmp(dict[i].english, dict[j].english) > 0 THEN
                SET temp as dict[i]
                SET dict[i] as dict[j]
                SET dict[j] as temp
            END IF
        END FOR
    END FOR
END FUNCTION

FUNCTION Algorithm1(dict1[], dict2[], result[], index)
    SET i as 0
    SET j as 0
    SET head as -1
    
    WHILE dict1[i].english[0] != '\0'
        CALL Insertion(result, dict1[i], head)
        SET head as 0
        INCREMENT i
    END WHILE
    
    WHILE dict2[j].english[0] != '\0'
        CALL Insertion(result, dict2[j], head)
        SET head as 0
        INCREMENT j
    END WHILE
END FUNCTION

FUNCTION Algorithm2(dict1[], dict2[], result[], index)
    SET i as index
    SET j as index
    SET k as 0
    
    WHILE dict1[i].english[0] != '\0' OR dict2[j].english[0] != '\0'
        IF dict1[i].english[0] == '\0' THEN
            SET result[k] as dict2[j]
            INCREMENT j
        ELSE IF dict2[j].english[0] == '\0' THEN
            SET result[k] as dict1[i]
            INCREMENT i
        ELSE IF strcmp(dict1[i].english, dict2[j].english) < 0 THEN
            SET result[k] as dict1[i]
            INCREMENT i
        ELSE
            SET result[k] as dict2[j]
            INCREMENT j
        END IF
        
        INCREMENT k
    END WHILE
END FUNCTION

FUNCTION main()
    DECLARE dict1 as array of struct Dictionary with size 4
    SET dict1[0] as {"ab", "e"}
    SET dict1[1] as {"b", "a"}
    SET dict1[2] as {"d", "q"}
    SET dict1[3] as {"", ""}
    
    DECLARE dict2 as array of struct Dictionary with size 4
    SET dict2[0] as {"ac", "q"}
    SET dict2[1] as {"c", "q"}
    SET dict2[2] as {"z", "s"}
    SET dict2[3] as {"", ""}
    Algorithm1
    PRINT result
    END FUNCTION
    Algorithm2
    PRINT result
    END FUNCTION
END FUNCTION

*/