# PAS. 研究生初试录取系统及其扩展

## 前言

大一下 $\texttt{C++}$ 的课程设计作业。 

## 课设基本要求

研究生考试课程为4门，其中数学、外语、政治为统一命题，而专业基础课则根据不同的专业由招生学校自行命题。国家对初试录取分数有总分要求（如某一年要求4门课总分应达到310分），另外还有对每门课的最低分数要求（如总分为100的试卷最低应达到40分，总分为150的试卷最低应达到65分）。

## 功能需求

1. 设计菜单实现功能选择；
2. 能够新增、修改和删除学生的信息，包括：考生姓名，准考证号，报考专业，是否应届生，4门课程（政治、数学、外语、专业基础课）成绩；
3. 能统计初试合格的人数，并按总分由高到低的顺序输出合格考生的信息。
4. 程序运行时首先要求将考生信息这些原始数据应保存到一个文件中；然后输入：录取的总分要求，各课程的最低分数要求；输出要求：过线考生的姓名，准考证号，报考专业，是否应届生，4门课程（政治、数学、外语、专业基础课）成绩及总分，这些信息应存放到另一个文件中。

个人采用：链表实现一个简易的键值对匹配的数据结构。

除了基本功能以外，还设计了考生登录查分系统和提交审核分数工单的功能。

---

The course design assignment for C++ in the second semester of freshman year.

The graduate entrance examination consists of four subjects, namely, Mathematics, Foreign Language, Politics, which are uniformly examined, while the professional basic courses are subject to the propositions set by the admitting institution according to different majors. The state has a total score requirement for the admission score of the first round of examination (such as requiring a total score of 310 for four subjects in a certain year), and there are also minimum score requirements for each subject (such as the minimum score for a test paper with a total score of 100 should be 40, and the minimum score for a test paper with a total score of 150 should be 65).

- I used linked list to implement a simple key-value pair matching data structure.

- In addition to the basic functions, I also designed a score inquiry system for examinees to log in and submit a score review work order.