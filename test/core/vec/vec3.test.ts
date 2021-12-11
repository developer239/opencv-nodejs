import { Vec3 } from '../../../index'

describe('[core] Vec3', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const vec = new Vec3(9, 8, 7)

      expect(vec.x).toStrictEqual(9)
      expect(vec.y).toStrictEqual(8)
      expect(vec.z).toStrictEqual(7)
    })

    it('should update instance properties', () => {
      const vec = new Vec3(4, 3, 2)

      vec.x = 88
      vec.y = 77
      vec.z = 66

      expect(vec.x).toStrictEqual(88)
      expect(vec.y).toStrictEqual(77)
      expect(vec.z).toStrictEqual(66)
    })
  })
})
