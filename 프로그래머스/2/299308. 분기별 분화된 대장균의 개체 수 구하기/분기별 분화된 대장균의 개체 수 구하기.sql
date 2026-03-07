-- 코드를 작성해주세요
# 1,2,3 -> 1분기
# 4,5,6 -> 2분기
# 7,8,9 -> 3분기
# 10,11, 12 -> 4분기

select quarter, count(*) ecoli_count from
(select 
case when month(differentiation_date) between 1 and 3 then '1Q'
when month(differentiation_date) between 4 and 6 then '2Q'
when month(differentiation_date) between 7 and 9 then '3Q'
else '4Q'
end as quarter
from ecoli_data) d group by quarter order by quarter