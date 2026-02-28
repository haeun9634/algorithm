-- 코드를 입력하세요
-- SELECT flavor from first_half as f join july as j on f.flavor = o.flavor




SELECT f.flavor
FROM first_half f
JOIN july j
ON f.flavor = j.flavor
GROUP BY f.flavor
ORDER BY (f.total_order + SUM(j.total_order)) DESC
LIMIT 3;