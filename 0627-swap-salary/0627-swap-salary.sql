update salary
set sex = (
    case
        when sex = 'f' then 'm'
        else 'f'
    end
)
where true