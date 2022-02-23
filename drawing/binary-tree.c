// Render binary tree to html
//
// Run:
//   ./a.out 123##4a##b##5678###9##x## > binary_tree.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *link;
struct node {
    int Item;
    link L, R; // pointers to left and right child
    int H;     // height of the node
    int width; // width of the subtree in the painting
    float root_pos;
    int x, y;
};

#define NEW_NODE(i)                 \
    ({                              \
        link t = malloc(sizeof *t); \
        t->Item = i;                \
        t->L = t->R = NULL;         \
        t->H = 0;                   \
        t->width = 2;               \
        t->root_pos = 0.0f;         \
        t->x = t->y = 0;            \
        t;                          \
    })

#define RADIUS 20
#define PADDING 1
#define X_POS(t) (g_cur_x + t->width * RADIUS / 2)
#define Y_POS(h) ((h + 1) * 2 * RADIUS - RADIUS + h * PADDING * RADIUS)

int traverse_for_size(link t) {
    if (t == NULL)
        return 0;
    int lh = traverse_for_size(t->L);
    int rh = traverse_for_size(t->R);
    t->H = lh > rh ? lh + 1 : rh + 1;
    if (t->L != NULL && t->R != NULL)
        t->width = t->L->width + t->R->width + PADDING;
    else if (t->L != NULL)
        t->width = 2 + t->L->width + PADDING;
    else if (t->R != NULL)
        t->width = 2 + t->R->width + PADDING;
    else
        t->width = 2;
    return t->H;
}

int g_cur_x;

void traverse_for_position(link t, int h) {
    if (t == NULL)
        return;
    t->x = X_POS(t);
    t->y = Y_POS(h);
    traverse_for_position(t->L, h + 1);
    int _x = g_cur_x;
    if (t->L != NULL)
        g_cur_x += RADIUS * (t->L->width + PADDING);
    else
        g_cur_x += RADIUS * (2 + PADDING);
    traverse_for_position(t->R, h + 1);
    g_cur_x = _x;
}

#define MAX_NODES 100
const char *g_circles[MAX_NODES];
const char *g_lines[MAX_NODES];
const char *g_texts[MAX_NODES];
int g_lines_cnt;
int g_circles_cnt;
int g_texts_cnt;

const char *CIRCLE = "<circle cx=%d cy=%d r=%d stroke=black fill=\"#f5f5f5\" />";
const char *LINE = "<line x1=%d y1=%d x2=%d y2=%d style=\"stroke:grey;stroke-width:2\" />";
const char *TEXT = "<text x=%d y=%d dx=-7 dy=5>%c</text>";

void create_circle(link a) {
    char *s = malloc(strlen(CIRCLE) + 20);
    sprintf(s, CIRCLE, a->x, a->y, RADIUS);
    g_circles[g_circles_cnt++] = s;
}

void create_line(link a, link b) {
    char *s = malloc(strlen(LINE) + 20);
    sprintf(s, LINE, a->x, a->y, b->x, b->y);
    g_lines[g_lines_cnt++] = s;
}

void create_text(link a) {
    char *s = malloc(strlen(TEXT) + 20);
    sprintf(s, TEXT, a->x, a->y, a->Item);
    g_texts[g_texts_cnt++] = s;
}

void traverse_for_html(link t) {
    if (t == NULL)
        return;
    create_circle(t);
    create_text(t);
    if (t->L) {
        create_line(t, t->L);
        traverse_for_html(t->L);
    }
    if (t->R) {
        create_line(t, t->R);
        traverse_for_html(t->R);
    }
}

link build_tree(char **ps) {
    char c = **ps;
    (*ps)++;
    if (c == '#' || c == '\0')
        return NULL;
    link x = malloc(sizeof *x);
    x->Item = c;
    x->L = build_tree(ps);
    x->R = build_tree(ps);
    return x;
}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    link tree = build_tree(&s);

    traverse_for_size(tree);
    traverse_for_position(tree, 0);
    traverse_for_html(tree);

    char *elements = malloc(
        g_lines_cnt * (strlen(LINE) + 20) +
        g_circles_cnt * (strlen(CIRCLE + 20)) +
        g_texts_cnt * (strlen(TEXT + 20)) +
        g_circles_cnt);
    for (int i = 0; i < g_lines_cnt; i++) {
        elements = strcat(elements, g_lines[i]);
        elements = strcat(elements, "\n");
    }
    for (int i = 0; i < g_circles_cnt; i++) {
        elements = strcat(elements, g_circles[i]);
        elements = strcat(elements, "\n");
    }
    for (int i = 0; i < g_texts_cnt; i++) {
        elements = strcat(elements, g_texts[i]);
        elements = strcat(elements, "\n");
    }

    char buf[2048]; // 2KB for the html text
    char *html = buf;
    html = strcat(html, "<!DOCTYPE html><html><body>\n<svg height=\"800\" width=\"800\">\n");
    html = strcat(html, elements);
    html = strcat(html, "</svg>\n</body></html>");
    printf("%s\n", html);

    return 0;
}
