
#include "ft_printf.h"
#include "libft.h"

/*
** Extract the next value in the va_list and update the right member of the
** union based on the value of the length modifier:
**   - LEN_MOD_CAP_L (`L'): long double
**   - else: double
** If the value equals zero, set the FL_NULL flag.
** If the value is negative (sign bit equals 1), and the value is not `nan',
** set the `is_neg' flag to 1.
*/

static t_dbls	*get_dbl_arg_val(t_dbls *arg_val, t_format *conv_params,
                                  va_list args)
{
    if (conv_params->len_mod == LEN_MOD_CAP_L)
    {
        if (!(arg_val->ldbl = (long double)va_arg(args, long double)))
        conv_params->flags |= FL_NULL;
        if (arg_val->ldbl_parts.sign
            && !(arg_val->ldbl_parts.exponent == 0x7FFF
                 && arg_val->ldbl_parts.mantissa))
            conv_params->is_neg = 1;
    }
    else
    {
        if (!(arg_val->dbl = (double)va_arg(args, double)))
        conv_params->flags |= FL_NULL;
        if (arg_val->dbl_parts.sign
            && !(arg_val->dbl_parts.exponent == 0x7FF
                 && arg_val->dbl_parts.mantissa))
            conv_params->is_neg = 1;
    }
    return (arg_val);
}

static char		*update_flags_limit_values(char *val_str, t_format *conv_params)
{
    if (conv_params->flags & FL_ZERO)
        conv_params->flags ^= FL_ZERO;
    if (!ft_strcmp(val_str, "nan"))
    {
        conv_params->flags |= (FL_PLUS | FL_SPACE);
        conv_params->flags ^= (FL_PLUS | FL_SPACE);
    }
    if (ft_isupper(conv_params->type_char))
        ft_strupper(val_str);
    return (val_str);
}

/*
** Convert the double value to a string with the right precision.
*/

static char		*dbl_arg_val_to_str(t_dbls *arg_val, t_format *conv_params)
{
    char		*digits;
    char		*val_str;
    int			exponent;

    if (is_limit_value(arg_val, conv_params))
    {
        if (!(val_str = handle_dbl_limit_values(arg_val, conv_params)))
            return (NULL);
        return (update_flags_limit_values(val_str, conv_params));
    }
    if (!(digits = ft_strnew(BUF_DIGITS_SIZE)))
        return (NULL);
    exponent = 0;
    if (!(conv_params->flags & FL_NULL))
        dragon4(arg_val, digits, &exponent, conv_params);
    else
        digits[0] = '0';
    if (ft_tolower(conv_params->type_char) == 'g')
        handle_g_conv_spec(exponent, conv_params);
    val_str = handle_dbl_precision(&digits, exponent, conv_params);
    ft_strdel(&digits);
    return (val_str);
}

static char		*format_dbl_str(char *val_str, t_format *conv_params)
{
    int			padding;
    int			nb_digits;
    int			nb_zeros_prec;

    nb_digits = ft_strlen(val_str);
    nb_zeros_prec = get_nb_zeros_prec_dbl(nb_digits, conv_params);
    if (nb_zeros_prec)
        if (!prepend_prec(&val_str, nb_zeros_prec))
            return (NULL);
    if (has_sign(1, conv_params))
        if (!prepend_sign(&val_str, conv_params))
            return (NULL);
    if ((padding = conv_params->width - ft_strlen(val_str)) > 0)
        if (!add_padding(&val_str, padding, conv_params))
            return (NULL);
    return (val_str);
}

char			*get_formatted_str_from_dbl(t_format *conv_params, va_list args)
{
    t_dbls		arg_val;
    char		*val_str;

    arg_val.ldbl = 0.L;
    if (!(conv_params->flags & FL_PREC))
        conv_params->prec = 6;
    get_dbl_arg_val(&arg_val, conv_params, args);
    if (!(val_str = dbl_arg_val_to_str(&arg_val, conv_params)))
        return (NULL);
    if (!(val_str = format_dbl_str(val_str, conv_params)))
        return (NULL);
    return (val_str);
}
