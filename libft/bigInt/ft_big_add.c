t_bigint    ft_big_add(t_bigint fNum, t_bigint sNum)
{
    t_bigint result;
    int i;
    unsigned long carry;
    unsigned long sum;
    size_t max_len;

    carry = 0;
    i = 0;
    result = (t_bigint){0, {0}};
    max_len = (size_t)ft_max(bigint1->length, bigint2->length);
    while (i < maxlen) {
        sum = carry + fNum.blocks[i] + sNum.blocks[i];
        result.blocks[i] = sum & 0xFFFFFFFF;
        carry = sum >> 32;
        i++;
    }
    if (carry && (i < BIGINT_SIZE))
        result.blocks[i] = carry & 0xFFFFFFFF;
    if (carry)
        result.length = max_length + 1;
    else
        result.length = max_length;
    return (result);
}

t_bigint		*ft_bigint_multiply(const t_bigint *bigint1,
                                    const t_bigint *bigint2, t_bigint *result)
{
    const t_bigint	*large_nb;
    const t_bigint	*small_nb;
    t_bigint		bigint_tmp;
    size_t			i;
    int				shift;

    i = 0;
    shift = 0;
    ft_bigint_order(bigint1, bigint2, &small_nb, &large_nb);
    while (i < small_nb->length)
    {
        bigint_tmp = (t_bigint){0, {0}};
        ft_bigint_cpy(&bigint_tmp, large_nb);
        ft_bigint_multiply_uint(&bigint_tmp, small_nb->blocks[i]);
        ft_bigint_shiftleft(&bigint_tmp, shift * BIGINT_BLOCK_SIZE);
        *result = ft_bigint_add(result, bigint_tmp);
        ++i;
        ++shift;
    }
    return (result);
}

int				ft_bigint_divide(const t_bigint *dividend,
                                    const t_bigint *divisor)
{
    int				res;
    t_bigint		bigint_tmp;

    res = 5;
    bigint_tmp = (t_bigint){0, {0}};
    ft_bigint_multiply_uint(ft_bigint_cpy(&bigint_tmp, divisor), res);
    if (ft_bigint_comp(dividend, &bigint_tmp) > 0)
    {
        bigint_tmp = ft_bigint_add(bigint_tmp, *divisor);
        while (ft_bigint_comp(dividend, bigint_tmp) > 0) {
            bigint_tmp = ft_bigint_add(bigint_tmp, *divisor);
            ++res;
        }
            return (!ft_bigint_comp(dividend, &bigint_tmp) ? res + 1 : res);
    }
    if (ft_bigint_comp(dividend, &bigint_tmp) < 0)
    {
        while (ft_bigint_comp(dividend, ft_bigint_subst(&bigint_tmp, divisor,
                                                        &bigint_tmp)) < 0)
            --res;
        return (res - 1);
    }
    return (res);
}