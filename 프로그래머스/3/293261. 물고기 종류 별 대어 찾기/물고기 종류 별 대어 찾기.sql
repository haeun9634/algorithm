-- 코드를 작성해주세요

select id, fish_name, length from fish_info fi join fish_name_info fn on fi.fish_type = fn.fish_type 
where (fi.fish_type, fi.length) in (select fish_type, max(fii.length) from fish_info fii group by fii.fish_type)
order by id

