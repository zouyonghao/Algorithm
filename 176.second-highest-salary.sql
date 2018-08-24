#
# [176] Second Highest Salary
#
# https://leetcode-cn.com/problems/second-highest-salary/description/
#
# database
# Easy (24.37%)
# Total Accepted:    6.7K
# Total Submissions: 27.6K
# Testcase Example:  '{"headers": {"Employee": ["Id", "Salary"]}, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}'
#
# 编写一个 SQL 查询，获取 Employee 表中第二高的薪水（Salary） 。
# 
# +----+--------+
# | Id | Salary |
# +----+--------+
# | 1  | 100    |
# | 2  | 200    |
# | 3  | 300    |
# +----+--------+
# 
# 
# 例如上述 Employee 表，SQL查询应该返回 200 作为第二高的薪水。如果不存在第二高的薪水，那么查询应返回 null。
# 
# +---------------------+
# | SecondHighestSalary |
# +---------------------+
# | 200                 |
# +---------------------+
# 
# 
#
# Write your MySQL query statement below

-- select Max(Salary) SecondHighestSalary
-- from Employee where (select Max(Salary) from Employee) > Salary
select IFNULL 
((select distinct Salary from Employee order by Salary DESC Limit 1,1),NULL)
as SecondHighestSalary;