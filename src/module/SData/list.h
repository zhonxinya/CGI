/*********************************** 
文件名：kernel link list of linux.h
作者：Bumble Bee
日期：2015-1-31 
功能：移植linux内核链表 
************************************/

/*链表结点数据结构*/
struct list_head 
{
    struct list_head *next, *prev;
};


static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}


static inline void __list_add(struct list_head *new,
                  struct list_head *prev, struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}
extern void __list_add(struct list_head *new,
               struct list_head *prev, struct list_head *next);

/**************************************
函数名：  list_add
参数：    @new：要插入结点的指针域
          @head：要插入链表表头的指针域
返回值：  无
函数功能：在已知链表头部插入新节点
**************************************/
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

#define list_for_each(pos, head)     for (pos = (head)->next;pos != (head);         pos = pos->next)



#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define container_of(ptr, type, member) ({                const typeof(((type *)0)->member) * __mptr = (ptr);        (type *)((char *)__mptr - offsetof(type, member)); })

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)


static inline void __list_del(struct list_head *prev, struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}
static inline void list_del(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
}