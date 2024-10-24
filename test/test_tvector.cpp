#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(v);

  ASSERT_EQ(v, v1);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(v);

  EXPECT_NE(&v, &v1);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.get_size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(4);

    ASSERT_ANY_THROW(v[-2] = 4);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(4);

    ASSERT_ANY_THROW(v[5] = 4);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(4);

    ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(4);
    TDynamicVector<int> v1(4);

    ASSERT_NO_THROW(v = v1);
=======
    int size = 4;
    TDynamicVector<int> v(size);
    TDynamicVector<int> v1(size);
    v1 = v;

    EXPECT_EQ(v, v1);
>>>>>>> master
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> v(4);
    TDynamicVector<int> v1(5);
    v = v1;

    ASSERT_EQ(v.get_size(), v1.get_size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(4);
    TDynamicVector<int> v1(5);

    ASSERT_NO_THROW(v = v1);
=======
    int size1 = 4, size2 = 7;
    TDynamicVector<int> v(size2);
    v[6] = 1;
    TDynamicVector<int> v1(size1);
    v1 = v;
    TDynamicVector<int> res(size2);
    res[6] = 1;

    EXPECT_EQ(v1, res);
>>>>>>> master
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    TDynamicVector<int> v(4);
    TDynamicVector<int> v1(4);

    ASSERT_EQ(v == v1, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    
    TDynamicVector<int> v(4);


    ASSERT_EQ(v == v, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> v(4);
    TDynamicVector<int> v1(5);

    ASSERT_EQ(v == v1, false);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    TDynamicVector<int> v(3);
    TDynamicVector<int> v1(3);

    v = v + 1;
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;

    EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);

    v = v - 2;
    v1[0] = -2;
    v1[1] = -2;

    EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);

    v[0] = 1;
    v[1] = 1;
    v = v * 2.0;
    v1[0] = 2;
    v1[1] = 2;

    EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);
    v[0] = 1;
    v[1] = 1;
    v1[0] = 2;
    v1[1] = 2;

    ASSERT_NO_THROW(v + v1);
=======
    int size1 = 2;
    TDynamicVector<int> v(size1);
    TDynamicVector<int> v1(size1);
    v[0] = 1;
    v[1] = 2;
    v1[0] = 2;
    v1[1] = 1;
    TDynamicVector<int> res(size1);
    res[0] = 3;
    res[1] = 3;
    EXPECT_EQ(v + v1, res);
>>>>>>> master

}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(1);

    v[0] = 1;
    v[1] = 1;
    v1[0] = 2;


    ASSERT_ANY_THROW(v + v1);
=======
    int size1 = 2, size2 = 4;
    TDynamicVector<int> v(size1);
    TDynamicVector<int> v1(size2);
    v[0] = 1;
    v[1] = 2;
    v1[0] = 2;
    v1[1] = 1;
    v1[2] = 1;
    v1[3] = 1;
    TDynamicVector<int> res(size2);
    res[0] = 3;
    res[1] = 3;
    res[2] = 1;
    res[3] = 1;
    EXPECT_EQ(v + v1, res);
>>>>>>> master
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);
    v[0] = 1;
    v[1] = 1;
    v1[0] = 2;
    v1[1] = 2;

    ASSERT_NO_THROW(v - v1);
=======
    int size1 = 2;
    TDynamicVector<int> v(size1);
    TDynamicVector<int> v1(size1);
    v[0] = 1;
    v[1] = 2;
    v1[0] = 2;
    v1[1] = 1;
    TDynamicVector<int> res(size1);
    res[0] = -1;
    res[1] = 1;
    EXPECT_EQ(v - v1, res);
>>>>>>> master
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);
    v[0] = 1;
    v[1] = 1;
    v1[0] = 2;
    

    ASSERT_NO_THROW(v - v1);
=======
    int size1 = 2, size2 = 4;
    TDynamicVector<int> v(size1);
    TDynamicVector<int> v1(size2);
    v[0] = 1;
    v[1] = 2;
    v1[0] = 2;
    v1[1] = 1;
    v1[2] = 1;
    v1[3] = 1;
    TDynamicVector<int> res(size2);
    res[0] = -1;
    res[1] = 1;
    res[2] = -1;
    res[3] = -1;
    EXPECT_EQ(v - v1, res);
>>>>>>> master
}
    

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);
    v[0] = 1;
    v[1] = 1;
    v1[0] = 2;
    v1[1] = 2;

    ASSERT_NO_THROW(v * v1);
=======
    int size1 = 2;
    TDynamicVector<int> v(size1);
    TDynamicVector<int> v1(size1);
    v[0] = 1;
    v[1] = 2;
    v1[0] = 2;
    v1[1] = 1;
    int res = 4;
    EXPECT_EQ(v * v1, res);
>>>>>>> master
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
<<<<<<< HEAD
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);
    v[0] = 1;
    v[1] = 1;
    v1[0] = 2;

    ASSERT_NO_THROW(v * v1);
=======
    int size1 = 2, size2 = 4;
    TDynamicVector<int> v(size1);
    TDynamicVector<int> v1(size2);
    v[0] = 1;
    v[1] = 2;
    v1[0] = 2;
    v1[1] = 1;
    v1[2] = 1;
    v1[3] = 1;
    int res = 4;
    EXPECT_EQ(v * v1, res);
>>>>>>> master
}

TEST(TDynamicVector, move_constructor_check)
{
    const int size = 10;
    TDynamicVector<int> v1(size);
    TDynamicVector<int> res(v1);

    TDynamicVector<int> v2(std::move(v1));

    EXPECT_EQ(v2, res);
}

TEST(TDynamicVector, move_opertor_check)
{
    const int size = 2;
    TDynamicVector<int> v1(size);
    TDynamicVector<int> res(v1);

    TDynamicVector<int> v2 = std::move(v1);

    EXPECT_EQ(v2, res);
}