import { Vec4 } from '../../../index'

describe('[core] Vec4', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const vec = new Vec4(5, 4, 3, 2)

      expect(vec.x).toStrictEqual(5)
      expect(vec.y).toStrictEqual(4)
      expect(vec.z).toStrictEqual(3)
      expect(vec.w).toStrictEqual(2)
    })

    it('should update instance properties', () => {
      const vec = new Vec4(4, 3, 2, 1)

      vec.x = 88
      vec.y = 77
      vec.z = 66
      vec.w = 55

      expect(vec.x).toStrictEqual(88)
      expect(vec.y).toStrictEqual(77)
      expect(vec.z).toStrictEqual(66)
      expect(vec.w).toStrictEqual(55)
    })
  })
})
