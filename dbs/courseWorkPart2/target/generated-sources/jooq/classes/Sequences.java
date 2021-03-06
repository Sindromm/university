/**
 * This class is generated by jOOQ
 */
package classes;


import javax.annotation.Generated;

import org.jooq.Sequence;
import org.jooq.impl.SequenceImpl;


/**
 * Convenience access to all sequences in public
 */
@Generated(
    value = {
        "http://www.jooq.org",
        "jOOQ version:3.8.6"
    },
    comments = "This class is generated by jOOQ"
)
@SuppressWarnings({ "all", "unchecked", "rawtypes" })
public class Sequences {

    /**
     * The sequence <code>public.person_schedule_sched_id_seq</code>
     */
    public static final Sequence<Long> PERSON_SCHEDULE_SCHED_ID_SEQ = new SequenceImpl<Long>("person_schedule_sched_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.persons_person_id_seq</code>
     */
    public static final Sequence<Long> PERSONS_PERSON_ID_SEQ = new SequenceImpl<Long>("persons_person_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.positions_position_id_seq</code>
     */
    public static final Sequence<Long> POSITIONS_POSITION_ID_SEQ = new SequenceImpl<Long>("positions_position_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.product_amounts_product_id_seq</code>
     */
    public static final Sequence<Long> PRODUCT_AMOUNTS_PRODUCT_ID_SEQ = new SequenceImpl<Long>("product_amounts_product_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.product_prices_product_id_seq</code>
     */
    public static final Sequence<Long> PRODUCT_PRICES_PRODUCT_ID_SEQ = new SequenceImpl<Long>("product_prices_product_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.products_product_id_seq</code>
     */
    public static final Sequence<Long> PRODUCTS_PRODUCT_ID_SEQ = new SequenceImpl<Long>("products_product_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.product_types_type_id_seq</code>
     */
    public static final Sequence<Long> PRODUCT_TYPES_TYPE_ID_SEQ = new SequenceImpl<Long>("product_types_type_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.sell_log_log_id_seq</code>
     */
    public static final Sequence<Long> SELL_LOG_LOG_ID_SEQ = new SequenceImpl<Long>("sell_log_log_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));

    /**
     * The sequence <code>public.shops_shop_id_seq</code>
     */
    public static final Sequence<Long> SHOPS_SHOP_ID_SEQ = new SequenceImpl<Long>("shops_shop_id_seq", Public.PUBLIC, org.jooq.impl.SQLDataType.BIGINT.nullable(false));
}
