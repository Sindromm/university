/**
 * This class is generated by jOOQ
 */
package classes.routines;


import classes.Public;

import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Parameter;
import org.jooq.impl.AbstractRoutine;


/**
 * This class is generated by jOOQ.
 */
@Generated(
    value = {
        "http://www.jooq.org",
        "jOOQ version:3.8.6"
    },
    comments = "This class is generated by jOOQ"
)
@SuppressWarnings({ "all", "unchecked", "rawtypes" })
public class AddShop extends AbstractRoutine<Integer> {

    private static final long serialVersionUID = 1529204379;

    /**
     * The parameter <code>public.add_shop.RETURN_VALUE</code>.
     */
    public static final Parameter<Integer> RETURN_VALUE = createParameter("RETURN_VALUE", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_shop.street</code>.
     */
    public static final Parameter<String> STREET = createParameter("street", org.jooq.impl.SQLDataType.CLOB, false, false);

    /**
     * Create a new routine call instance
     */
    public AddShop() {
        super("add_shop", Public.PUBLIC, org.jooq.impl.SQLDataType.INTEGER);

        setReturnParameter(RETURN_VALUE);
        addInParameter(STREET);
    }

    /**
     * Set the <code>street</code> parameter IN value to the routine
     */
    public void setStreet(String value) {
        setValue(STREET, value);
    }

    /**
     * Set the <code>street</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setStreet(Field<String> field) {
        setField(STREET, field);
    }
}
